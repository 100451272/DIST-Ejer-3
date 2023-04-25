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
        int init(void) = 1;
        int set_value(tupla tupla) = 2;
        tupla get_value(int key) = 3;
        int modify_value(tupla tupla) = 4;
        int delete_key(int key) = 5;
        int exist(int key) = 6;
        int copy_key(double_key keys) = 7;
    } = 1;
} = 1;