#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int read(char *text);

int main() {

    srand(time(NULL));

    int n1 = read("Enter original array size:");
    int *a1 = malloc(sizeof(int) * n1);
    for (int i = 0; i < n1; i++) {
        a1[i] = 100;
        printf("%d ", a1[i]);
    }

    int n2 = read("\nEnter new array size: ");
    a1 = realloc(a1, sizeof(int) * n2);
    for (int i = 0; i < n2; i++) {
        if (i >= n1) a1[i] = 0;
        printf("%d ", a1[i]);
    }

    return (0);
}

int read(char *text) {
    char *end, *start = (char *) malloc(sizeof(char) * 255);
    printf("%s", text);
    scanf("%s", start);
    return (int) strtol(start, &end, 10);
}
