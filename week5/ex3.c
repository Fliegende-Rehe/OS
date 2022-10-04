#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int is_prime(int n);

void write_in_file(long time);

void *prime_counter(void *arg);

int primes_count_in_interval(int start, int finish);

typedef struct prime_counter_request {
    int start, finish;
} prime_counter_request;

int main(int argc, char *argv[]) {
    time_t t0 = time(NULL);

    int n = (int) strtol(argv[1], NULL, 10),
            m = (int) strtol(argv[2], NULL, 10),
            segment_size = n / m;

    pthread_t *tid =
            (pthread_t *) malloc(m * sizeof(pthread_t));

    prime_counter_request *requests =
            (prime_counter_request *) malloc(m * sizeof(prime_counter_request));

    void **results = (void **) malloc(m * sizeof(void *));

    for (int i = 0; i < m; i++) {
        (requests + i)->start = i * segment_size;
        (requests + i)->finish = (i + 1) * segment_size;
        pthread_create(&tid[i], NULL, &prime_counter, (void *) (requests + i));
    }

    if (n % m == 0) {
        (requests + m)->start = n - n % m + 1;
        (requests + m)->finish = n;
        pthread_create(&tid[m], NULL, &prime_counter, (void *) (requests + m));
    }

    for (int i = 0; i < m; i++) {
        void *sum = NULL;
        pthread_join(tid[i], &sum);
        results[i] = sum;
    }

    int total_result = 0;
    for (int i = 0; i < m; i++)
        total_result += (int) (size_t) results[i]; // *(int *) doesn't work
    printf("%d\n", total_result);

    write_in_file(time(NULL) - t0);

    free(tid);
    free(requests);
    free(results);

    exit(EXIT_SUCCESS);
}

void *prime_counter(void *arg) {
    struct prime_counter_request *a = (struct prime_counter_request *) arg;
    pthread_exit((void *) (size_t) (primes_count_in_interval(a->start, a->finish)));
}

int is_prime(int n) {
    if (n <= 1)
        return 0;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

int primes_count_in_interval(int start, int finish) {
    int ret = 0;
    for (int i = start; i < finish; i++)
        if (is_prime(i) != 0)
            ret++;
    return ret;
}

void write_in_file(long time) {
    FILE *file = fopen("ex3.txt", "a");
    char *str = (char *) malloc(sizeof(char) * 3);
    sprintf(str, "%ld ", time);
    fputs(str, file);
    free(str);
    fclose(file);
}