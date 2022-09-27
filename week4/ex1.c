#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <wait.h>

void print_id(clock_t t);

int main() {
    pid_t pid = fork();
    clock_t t = clock();
    if (pid != 0) {
        pid = fork();
        t = clock();
        int status = 0;
        if (pid != 0) {
            while (wait(&status) > 0);
            print_id(0);
        } else print_id(t);
    } else print_id(t);
}

void print_id(clock_t t) {
    printf("process %d parent %d time %ld\n", getpid(), getppid(), clock() - t);
}