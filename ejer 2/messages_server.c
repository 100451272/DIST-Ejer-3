/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include <stdbool.h>
#include <stdio.h>
#include "messages.h"
#include "list.h"

List list;

bool_t
init_1_svc(int *result, struct svc_req *rqstp)
{
	bool_t retval = 1;

	/*
	 * insert server code here
	 */
	init_list(&list);
	result= 0;
	printf("List Initialized\n");

	return retval;
}

bool_t
set_value_1_svc(tupla tupla, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */

	return retval;
}

bool_t
get_value_1_svc(int key, tupla *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */

	return retval;
}

bool_t
modify_value_1_svc(tupla tupla, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */

	return retval;
}

bool_t
delete_key_1_svc(int key, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */

	return retval;
}

bool_t
exist_1_svc(int key, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */

	return retval;
}

bool_t
copy_key_1_svc(double_key keys, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

	/*
	 * insert server code here
	 */

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
