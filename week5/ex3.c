#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <math.h>
#include <time.h>

int n, m, sum = 0;

void *func();
int isPrime(int number);

int main(int argc, char **argv) {
    time_t begin = time(NULL);

    n = (int) strtol(argv[1], NULL, 10);
    m = (int) strtol(argv[2], NULL, 10);
    pthread_t *tid = malloc(m * sizeof(pthread_t));
    for (int i = 0; i < m; i++)
        pthread_create(&tid[i], NULL, &func, NULL);
    for (int i = 0; i < m; i++)
        pthread_join(tid[i], NULL);
    printf("%d\n", sum);

    time_t end = time(NULL);

    FILE *file = fopen("ex3.txt", "a");
    char str[3];
    sprintf(str, "%ld ", end - begin);
    fputs(str, file);

    fclose(file);
    free(tid);
    pthread_exit(NULL);
}

void *func() {
    static int k = -1;
    k++;
    int st = k * n / m,
            fn = (k + 1) * n / m;
    for (int j = st; j < fn; j++) {
        if (isPrime(j)) sum++;
    }
}

int isPrime(int number) {
    for (int j = 2; j <= (int) sqrt(number) + 1; j++) {
        if (number % j == 0) return 0;
    }
    return 1;
}
