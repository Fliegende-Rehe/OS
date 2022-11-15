#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int *readFile(char *fileName);

void createTables();

int pageFaults(const int *input);

int frameSizeFaults(const int *input);

struct PageTable {
    int valid;
} *PageTable;

struct FrameTable {
    int pageNumber;
    int age;
} *FrameTable;

size_t pages, frames;

int main(int arg, char *argv[]) {
    int *input = readFile("Lab 09 input.txt");

    frames = (size_t) strtol(argv[1], NULL, 10);

    createTables();

    int miss = pageFaults(input) + frameSizeFaults(input);

    printf("Hit %lu Miss %d\n", pages - miss, miss);

    printf("Hit/Miss ratio %f\n", (double) (pages - miss) / miss);
}

void createTables() {
    // 2 * sizeof int to avoid Clang-Tidy: Suspicious usage of 'sizeof(A*)'; pointer to aggregate
    // no padding so sizeof struct = sizeof sum of all struct el
    PageTable = malloc(sizeof(int) * pages);
    FrameTable = malloc(2 * sizeof(int) * frames);
    for (int i = 0; i < (pages > frames ? pages : frames); i++) {
        if (i < pages) PageTable[i].valid = FALSE;
        if (i < frames) FrameTable[i].age = 0;
    }
}

int pageFaults(const int *input) {
    int miss = 0;
    for (int i = 0; i < pages && miss != frames; ++i) {
        int in = input[i];
        if (PageTable[in].valid) continue;
        FrameTable[i].pageNumber = in;
        PageTable[in].valid = TRUE;
        miss++;
    }
    return miss;
}

int oldestPage() {
    int index;
    for (int j = 0, oldest = -1; j < frames; j++) {
        if (oldest >= FrameTable[j].age) continue;
        oldest = FrameTable[j].age;
        index = j;
    }
    return index;
}

int frameSizeFaults(const int *input) {
    int miss = 0;
    for (int i = 0; i < pages; ++i) {
        int in = input[i];
        for (int j = 0; j < frames; j++) FrameTable[j].age++;
        if (PageTable[in].valid) continue;
        int old = oldestPage();
        PageTable[FrameTable[old].pageNumber].valid = FALSE;
        FrameTable[old].pageNumber = in;
        FrameTable[old].age = 0;
        PageTable[in].valid = TRUE;
        miss++;
    }
    return miss;
}

size_t countSpaces(const char *str) {
    size_t spaces = 0;
    for (size_t i = 0; str[i]; i++)
        if (str[i] == ' ') spaces++;
    return spaces;
}

int *parseInput(char *input) {
    pages = countSpaces(input) + 1;
    int *output = (int *) malloc(sizeof(int) * pages);
    char *end = input;
    for (int i = 0; *end; i++, input = end) {
        output[i] = (int) strtol(input, &end, 10);
        while (*end == ' ') end++;
    }
    return output;
}

size_t fileSize(FILE *file) {
    fseek(file, 0L, SEEK_END);
    size_t size = ftell(file);
    rewind(file);
    return size;
}

int *readFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    size_t size = fileSize(file);
    char *input = (char *) malloc(sizeof(char) * size);
    fgets(input, (int) size, file);
    fclose(file);
    return parseInput(input);
}
