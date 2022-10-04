#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define n 5

// create array of struct
struct Thread {
    long id;
    int i;
    char message[256];
};struct Thread thread[n];

// fill struct elements during thread routine
void *routine(void *arg) {
    static int j = -1; j++;
    thread[j].id = pthread_self();
    thread[j].i = j;
    sprintf(thread[j].message, "Hello from thread %d", thread[j].i);
    printf("id %ld\nmessage %s\n\n", thread[j].id, thread[j].message);
}

int main(void) {
    pthread_t pthread;
    for (int j = 0; j < n; ++j) {
        pthread_create(&pthread, NULL, &routine, (void *) pthread);
        printf("Thread %d is created\n", j);
    }
    pthread_exit(NULL);
}
