/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include <stdbool.h>
#include "messages.h"
#include "list.h"

List list;
pthread_mutex_t mutex;

bool_t
init_rpc_1_svc(int *result, struct svc_req *rqstp)
{
	bool_t retval = 1;

	/*
	 * insert server code here
	 */
	init_list(&list);
	pthread_mutex_init(&mutex, NULL);
	result= 0;
	printf("List Initialized\n");

	return retval;
}

bool_t
set_value_rpc_1_svc(tupla tupla, int *result,  struct svc_req *rqstp)
{
	bool_t retval = 1;

	/*
	 * insert server code here
	 */

	printf("Set Value:\n");
	pthread_mutex_lock(&mutex);
	if (exists(&list, tupla.clave)){
		printf("The tuple already exists\n");
		*result = 1;
		return retval;
	}
	struct tuple tuple;
	tuple.clave = tupla.clave;
	strcpy(tuple.valor1, tupla.valor1);
	tuple.valor2 = tupla.valor2;
	tuple.valor3 = tupla.valor3;
	set(&list, tupla.clave, &tuple);
	pthread_mutex_unlock(&mutex);
	*result = 0;
	printList(list);

	return retval;
}

bool_t
get_value_rpc_1_svc(int key, tupla *result,  struct svc_req *rqstp)
{
	bool_t retval = 1;

	/*
	 * insert server code here
	 */
	printf("Get Value\n");
	struct tuple tuple;
	pthread_mutex_lock(&mutex);
	int resultado = get(&list, key, &tuple);
		if (resultado == 0) { // si la operación fue exitosa
			// copiamos los valores de la tupla a los campos de la respuesta
			result->clave = 0;
			strcpy(result->valor1, tuple.valor1);
			result->valor2 = tuple.valor2;
			result->valor3 = tuple.valor3;
		}
		else {
			result->clave = -1;
		}
	pthread_mutex_unlock(&mutex);
	return retval;
}

bool_t
modify_value_rpc_1_svc(tupla tupla, int *result,  struct svc_req *rqstp)
{
	bool_t retval = 1;

	/*
	 * insert server code here
	 */
	printf("Modify Value:\n");
	pthread_mutex_lock(&mutex);
	if (exists(&list, tupla.clave) == 0) {
            printf("La clave %d no existe\n", tupla.clave);
            *result = 1;
			return retval;
        }
	delete_node(&list, tupla.clave);
	struct tuple tuple;
	tuple.clave = tupla.clave;
	strcpy(tuple.valor1, tupla.valor1);
	tuple.valor2 = tupla.valor2;
	tuple.valor3 = tupla.valor3;
	set(&list, tupla.clave, &tuple);
	*result = 0;
	printList(list);
	pthread_mutex_unlock(&mutex);

	return retval;
}

bool_t
delete_key_rpc_1_svc(int key, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */
	printf("Delete Key:\n");
	pthread_mutex_lock(&mutex);
	if (!exists(&list, key)){
		printf("The tuple does not exist\n");
		*result = 1;
		return retval;
	}
	if (delete_node(&list, key) == 0) {
		*result = 0;
	} else {
		*result = 1;
	}
	printList(list);
	pthread_mutex_unlock(&mutex);
	return retval;
}

bool_t
exist_rpc_1_svc(int key, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */
	pthread_mutex_lock(&mutex);
	*result = exists(&list, key);
	pthread_mutex_unlock(&mutex);
	if (*result == 0) {
		printf("No existe\n");
	}
	else if (*result == 1){
		printf("Existe\n");
	}

	return retval;
}

bool_t
copy_key_rpc_1_svc(double_key keys, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */
	struct tuple tupla1, tupla2;
	pthread_mutex_lock(&mutex);
	// Buscar la tupla de key1
	if (get(&list, keys.key1, &tupla1) == -1) {
		*result = 1; // La clave key1 no existe
		return retval;
	}

	// Crear la tupla de key2 con los valores de key1
	tupla2.clave = keys.key2;
	strcpy(tupla2.valor1, tupla1.valor1);
	tupla2.valor2 = tupla1.valor2;
	tupla2.valor3 = tupla1.valor3;

	// Insertar o modificar la tupla en la lista
	delete_node(&list, tupla2.clave);
	set(&list, keys.key2, &tupla2);

	*result = 0;
	printList(list);
	pthread_mutex_unlock(&mutex);
	return retval;
}

int
messages_1_freeresult (SVCXPRT *transp, xdrproc_t xdr_result, caddr_t result)
{
	xdr_free (xdr_result, result);

	/*
	 * Insert additional freeing code here, if needed
	 */

	return 1;
}
