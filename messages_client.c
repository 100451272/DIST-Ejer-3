/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "messages.h"


void
messages_1(char *host)
{
	CLIENT *clnt;
	enum clnt_stat retval_1;
	int result_1;
	enum clnt_stat retval_2;
	int result_2;
	tupla  set_value_rpc_1_tupla;
	enum clnt_stat retval_3;
	tupla result_3;
	int get_value_rpc_1_key;
	enum clnt_stat retval_4;
	int result_4;
	tupla  modify_value_rpc_1_tupla;
	enum clnt_stat retval_5;
	int result_5;
	int delete_key_rpc_1_key;
	enum clnt_stat retval_6;
	int result_6;
	int exist_rpc_1_key;
	enum clnt_stat retval_7;
	int result_7;
	double_key copy_key_rpc_1_keys;

#ifndef	DEBUG
	clnt = clnt_create (host, MESSAGES, FIRST_VER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	retval_1 = init_rpc_1(&result_1, clnt);
	if (retval_1 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	retval_2 = set_value_rpc_1(set_value_rpc_1_tupla, &result_2, clnt);
	if (retval_2 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	retval_3 = get_value_rpc_1(get_value_rpc_1_key, &result_3, clnt);
	if (retval_3 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	retval_4 = modify_value_rpc_1(modify_value_rpc_1_tupla, &result_4, clnt);
	if (retval_4 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	retval_5 = delete_key_rpc_1(delete_key_rpc_1_key, &result_5, clnt);
	if (retval_5 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	retval_6 = exist_rpc_1(exist_rpc_1_key, &result_6, clnt);
	if (retval_6 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	retval_7 = copy_key_rpc_1(copy_key_rpc_1_keys, &result_7, clnt);
	if (retval_7 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}

void get_env(char* ip){
    
}

int init(void){
	char* ip = getenv("IP_TUPLAS");
    if (ip == NULL){
        printf("Variable IP_TUPLAS no definida\n");
        exit(-1);
    }
	CLIENT *clnt = clnt_create (ip, MESSAGES, FIRST_VER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip);
		exit (1);
	}
	enum clnt_stat retval;
	int result;
	retval = init_rpc_1(&result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);
	return result;
}

int modify(int key1, int key2){
	return 1;
}

int set_value(int key, char *value1, int value2, double value3){
	char* ip = getenv("IP_TUPLAS");
    if (ip == NULL){
        printf("Variable IP_TUPLAS no definida\n");
        exit(-1);
    }
	CLIENT *clnt = clnt_create (ip, MESSAGES, FIRST_VER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip);
		exit (1);
	}
	enum clnt_stat retval;
	int result;
	tupla tupla;
	tupla.clave = key;
	strcpy(tupla.valor1, value1);
	tupla.valor2 = value2;
	tupla.valor3 = value3;
	retval = set_value_rpc_1(tupla, &result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);
	return result;
}

int get_value(int key, char *value1, int *value2, double *value3){
	char* ip = getenv("IP_TUPLAS");
    if (ip == NULL){
        printf("Variable IP_TUPLAS no definida\n");
        exit(-1);
    }
	CLIENT *clnt = clnt_create (ip, MESSAGES, FIRST_VER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip);
		exit (1);
	}
	enum clnt_stat retval;
	tupla tupla;
	retval = get_value_rpc_1(key, &tupla, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);
	strcpy(value1, tupla.valor1);
	*value2 = tupla.valor2;
	*value3 = tupla.valor3;
	int result;
	if (tupla.clave != 0){
		result = 0;
	}
	else{
		result = 1;
	}
	return result;
}

int modify_value(int key, char *value1, int value2, double value3){
	char* ip = getenv("IP_TUPLAS");
    if (ip == NULL){
        printf("Variable IP_TUPLAS no definida\n");
        exit(-1);
    }
	CLIENT *clnt = clnt_create (ip, MESSAGES, FIRST_VER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip);
		exit (1);
	}
	enum clnt_stat retval;
	tupla tupla;
	tupla.clave = key;
	strcpy(tupla.valor1, value1);
	tupla.valor2 = value2;
	tupla.valor3 = value3;
	int result;
	retval = modify_value_rpc_1(tupla, &result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);
	
	return result;
}

int delete_key(int key){
	char* ip = getenv("IP_TUPLAS");
    if (ip == NULL){
        printf("Variable IP_TUPLAS no definida\n");
        exit(-1);
    }
	CLIENT *clnt = clnt_create (ip, MESSAGES, FIRST_VER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip);
		exit (1);
	}
	enum clnt_stat retval;
	int result;
	retval = delete_key_rpc_1(key, &result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);
	return result;
}

int exist(int key){
	char* ip = getenv("IP_TUPLAS");
    if (ip == NULL){
        printf("Variable IP_TUPLAS no definida\n");
        exit(-1);
    }
	CLIENT *clnt = clnt_create (ip, MESSAGES, FIRST_VER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip);
		exit (1);
	}
	enum clnt_stat retval;
	int result;
	retval = exist_rpc_1(key, &result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);
	return result;
}

int copy_key(int key1, int key2){
	char* ip = getenv("IP_TUPLAS");
    if (ip == NULL){
        printf("Variable IP_TUPLAS no definida\n");
        exit(-1);
    }
	CLIENT *clnt = clnt_create (ip, MESSAGES, FIRST_VER, "tcp");
	if (clnt == NULL) {
		clnt_pcreateerror (ip);
		exit (1);
	}
	enum clnt_stat retval;
	int result;
	double_key dkey;
	dkey.key1 = key1;
	dkey.key2 = key2;
	retval = copy_key_rpc_1(dkey, &result, clnt);
	if (retval != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	clnt_destroy (clnt);
	return result;
}

/*
int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	messages_1 (host);
exit (0);
}*/
