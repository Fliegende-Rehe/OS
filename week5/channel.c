#include<stdio.h>
#include<unistd.h>
#include <malloc.h>

int main() {
    int ipc[2];
    size_t len = 10 * sizeof(char);

    if (pipe(ipc) == -1)
        return 1;

    if (fork() == 0) {
        close(ipc[0]);
        char *input = (char *) malloc(len);
        printf("Publisher: ");
        scanf("%s", input);
        if (write(ipc[1], input, len) == -1)
            return 2;
        close(ipc[1]);
        free(input);
    } else {
        close(ipc[1]);
        char *output = (char *) malloc(len);
        if (read(ipc[0], output, len) == -1)
            return 3;
        close(ipc[0]);
        printf("Subscriber: %s\n", output);
        free(output);
    }

    return 0;
}