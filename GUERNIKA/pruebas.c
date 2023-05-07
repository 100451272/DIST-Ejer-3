#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <sys/wait.h>

void *set_value(void *arg) {
    int i = *(int *)arg;
    char command[100];
    sprintf(command, "./cliente set_value %d %d 1 1.0", i, i);
    system(command);
    return NULL;
}

int main(void) {
    pthread_t thread_id[20];
    int args[20], i;
    char command[100];
    

    
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        system("./servidor");
        exit(0);
    } else {

        setenv("IP_TUPLAS", "localhost", 1);
        strcpy(command, "./cliente init");
        system(command);
        
        for (i = 0; i < 20; i++) {
            args[i] = i + 1;
            pthread_create(&thread_id[i], NULL, set_value, &args[i]);
        }

        for (i = 0; i < 20; i++) {
            pthread_join(thread_id[i], NULL);
        }
        strcpy(command, "./cliente exists 20");
        system(command);

        system("./cliente modify_value 20 newvalue 100 420.69");

        system("./cliente copy_key 20 21");

        system("./cliente delete_key 1");
        sleep(3);
        if (kill(pid, SIGKILL) == -1) {
            perror("kill");
            exit(1);
        }
        if (wait(&status) == -1) {
            perror("wait");
            exit(1);
        }
        exit(0);
    }



    return 0;
}