
#ifndef P_CLAVES_H
#define P_CLAVES_H
int init(void);

int modify(int key1, int key2);

int set_value(int key, char *value1, int value2, double value3);

int get_value(int key, char *value1, int *value2, double *value3);

int modify_value(int key, char *value1, int value2, double value3);

int delete_key(int key);

int exist(int key);

int copy_key(int key1, int key2);
#endif //P_CLAVES_H