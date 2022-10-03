#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <string.h>
#include <stdint.h>

const int n = 5;

// create array of struct
struct Thread {
    int id;
    int i;
    char message[256];
};struct Thread thread[10];

// fill struct elements during thread routine
int j = 0;
void *routine(void *arg) {
    thread[j].id = (uintptr_t) arg;
    thread[j].i = j;
    sprintf(thread[j].message, "Hello form thread %d", thread[j].i);
    printf("id %d\nmessage %s\n\n", thread[j].id, thread[j].message);
    pthread_exit(NULL);
}

int main(void) {
    pthread_t pthread[n];
    for (j = 0; j < n; ++j) {
        pthread_create(&pthread[j], NULL, &routine, (void *) pthread[j]);
        printf("Thread %d is created\n", j);
        pthread_join(pthread[j], NULL);
    }
}



