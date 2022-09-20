#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int foo(const int *age);

int main() {
    // declare a pointer q to a constant integer x whose constant value is 10
    const int x = 10;
    int const *q = &x;

    // create 5 contiguous memory cells of type constant integer and referred by a constant pointer p
    int *const p = (const int *const) malloc(SIZE);

    // fill the cells with the value of x
    for (int i = 0; i < SIZE; ++i)
        *(p + i) = *q;

    // print the memory addresses of these cells to stdout
    for (int i = 0; i < SIZE; i++)
        printf("%p\n", p + i);

    // print the memory addresses of these cells to stdout
    for (int i = 0; i < SIZE; i++)
        scanf("%d", p + i);

    // calculate the birth year of the previous students and store them in the same allocated cells
    for(int i = 0; i < 5; ++i)
        *(p + i) = foo(p + i);

    // do not forget to free the allocated cells
    free((void *) p);

    return 0;
}

// write a function foo to calculate the birth year of the person, given the age
int foo(const int *age){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm.tm_year + 1900 - *age;
}
