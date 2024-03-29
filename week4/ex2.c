#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>

/* creates 2 vectors
 * fills them with random int */
int **randomization();

/* reads number of processes from stdin
 * creates an array of processes
 * calculates elements' products of vectors
 * writes them in file */
void calculation(int **v);

/* reads elements' products from file
 * aggregates them to get dot product */
long aggregation();

int main() {
    int **vectors = randomization();
    calculation(vectors);
    long dotProduct = aggregation();
    printf("%ld\n", dotProduct);
}

const int vectorSize = 120;

int **randomization() {
    int **uv = (int **) malloc(2 * sizeof(int *)); // create to vectors
    for (int i = 0; i < 2; i++) {
        uv[i] = (int *) malloc(sizeof(int) * vectorSize);
        for (int j = 0; j < vectorSize; j++)
            uv[i][j] = rand() % 100;
    }
    return uv;
}

size_t lineLen = 5; // line for product in temp.txt (sum of 99 * 99 len + '\n' symbol)
const char *fileName = "temp.txt";

void calculation(int **uv) {
    char *ptr, input[2];
    scanf("%s", input);
    int n = (int) strtol(input, &ptr, 10);
    pid_t *pids = (pid_t *) malloc(sizeof(pid_t) * n);
    FILE *file = fopen(fileName, "w");

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        int status = 0;
        if (pid != 0) {
            pids[i] = pid;
            while (wait(&status) > 0);
            continue;
        }
        for (int j = 0; j < vectorSize / n; j++) {
            char *product = (char *) malloc(sizeof(char) * lineLen);
            int index = (vectorSize / n) * i + j;
            sprintf(product, "%d\n", *(*uv + index) * *(*(uv + 1) + index));
            fputs(product, file);
            free(product);
        }
        exit(0);
    }
    free(pids);
    free(uv);
    fclose(file);
}

long aggregation() {
    FILE *file = fopen(fileName, "r");
    long sum = 0;
    char *ptr;
    char *line = (char *) malloc(sizeof(char) * lineLen);
    while (getline(&line, &lineLen, file) != -1)
        sum += strtol(line, &ptr, 10);
    free(line);
    fclose(file);
    return sum;
}
