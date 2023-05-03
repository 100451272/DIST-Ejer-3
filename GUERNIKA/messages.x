struct tupla {
    int clave;
    char valor1[255];
    int valor2;
    double valor3;
};

struct double_key {
    int key1;
    int key2;
};

program MESSAGES {
    version FIRST_VER {
        int init_rpc(void) = 1;
        int set_value_rpc(tupla tupla) = 2;
        tupla get_value_rpc(int key) = 3;
        int modify_value_rpc(tupla tupla) = 4;
        int delete_key_rpc(int key) = 5;
        int exist_rpc(int key) = 6;
        int copy_key_rpc(double_key keys) = 7;
    } = 1;
} = 1;