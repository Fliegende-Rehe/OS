#include <stdio.h>
#include <stdlib.h>

int read(char *text);

int main() {
    int n = read("Enter n:");
    int *array = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        *(array + i) = i;
        printf("%d ", array[i]);
    }
    free(array);
    return (0);
}

int read(char *text) {
    char *end, *start = (char *) malloc(sizeof(char) * 255);
    printf("%s", text);
    scanf("%s", start);
    return (int) strtol(start, &end, 10);
}
