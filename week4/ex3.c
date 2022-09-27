#include <unistd.h>
#include <stdlib.h>

int main(int arg, char *argv[]) {
    char *ptr;
    long n = strtol(argv[1], &ptr, 10);
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        sleep(5);
    }
}