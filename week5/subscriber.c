#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define FIFO "/tmp/ex1"
#define SIZE 1024

int main(int argc, char **argv) {
    printf("Subscriber here %s...\n\n", argv[1]);

    char input[SIZE];
    while(1) {
        int pipe = open(FIFO, O_RDONLY);
        if (pipe == -1)
            return 1;

        if(read(pipe, input, SIZE) != -1)
            printf("Published message: %s", input);

        close(pipe);
    }
}