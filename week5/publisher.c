#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

#define FIFO "/tmp/ex1"
#define SIZE 1024

int main(int argc, char **argv) {
    printf("Publisher here...\n\n");
    mkfifo(FIFO, 0777);

    char input[SIZE];
    while (1) {
        int pipe = open(FIFO, O_WRONLY);
        if (pipe == -1)
            return 1;

        printf("Enter message: ");
        fgets(input, SIZE, stdin);
        for(int i = 0; i < atoi(argv[1]); i++){
            if ((write(pipe, input, SIZE)) == -1)
                return 2;
        }


        close(pipe);

        sleep(1); // Make sure that the publisher can send only one message every second.
    }
}