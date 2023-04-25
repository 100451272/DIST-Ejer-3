#include "messages.h"

int main(int argc, char** argv) {
    // create the RPC client
    CLIENT* client = clnt_create("localhost", MESSAGES, FIRST_VER, "tcp");

    // call my_procedure_1
    //char* arg1 = "hello";
    int res;
    init_1(&res, client);
    // handle result

    // destroy the RPC client
    clnt_destroy(client);

    return 0;
}