#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


pthread_mutex_t global_lock = PTHREAD_MUTEX_INITIALIZER;

int n = 0, // number of int to check
k = 0, // next number to check
c = 0; // primes found so far

void write_in_file(long time);

int is_prime(int number);

int get_number_to_check();

void increment_primes();

void *check_primes(void *arg);

int main(int argc, char *argv[]) {
    time_t t0 = time(NULL);

    n = (int) strtol(argv[1], NULL, 10);
    int m = (int) strtol(argv[2], NULL, 10);

    pthread_t *tid = (pthread_t *) malloc(m * sizeof(pthread_t));

    pthread_mutex_init(&global_lock, NULL);

    for (int i = 0; i < m; i++)
        pthread_create(&tid[i], NULL, &check_primes, NULL);
    for (int i = 0; i < m; i++)
        pthread_join(tid[i], NULL);

    pthread_mutex_destroy(&global_lock);

    printf("%d\n", c);

    free(tid);
    write_in_file(time(NULL) - t0);
    exit(EXIT_SUCCESS);
}

void *check_primes(void *arg) {
    while (1) {
        pthread_mutex_lock(&global_lock);
        int next = get_number_to_check();
        pthread_mutex_unlock(&global_lock);

        if (next == n)
            return EXIT_SUCCESS;

        if (is_prime(next)) {
            pthread_mutex_lock(&global_lock);
            increment_primes();
            pthread_mutex_unlock(&global_lock);
        }
    }
}

int get_number_to_check() {
    int ret = k;
    if (k != n) k++;
    return ret;
}

void increment_primes() {
    c++;
}

int is_prime(int number) {
    if (number <= 1) return 0;
    for (int d = 2; d * d <= number; d++)
        if (number % d == 0) return 0;
    return 1;
}

void write_in_file(long time) {
    FILE *file = fopen("ex4.txt", "a");
    char *str = (char *) malloc(sizeof(char) * 3);
    sprintf(str, "%ld ", time);
    fputs(str, file);
    free(str);
    fclose(file);
}
