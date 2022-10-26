#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Builtin malloc() allocate a bit more space for array.
 *
 * As I understand is an optimisation. The guess is that,
 * if you use malloc() once, you will use it several more times.
 * So there is a single initial system call to extend process space.
 *
 * So I write my own malloc(), free() and sizeof().
 */

void *my_realloc(void *p_old, size_t size);

void *my_malloc(size_t size);

void *my_free(void *ptr);

size_t my_sizeof(void *ptr);

void print(int *p_a, int *p_b);

int main() {
    int *p_a, *p_b;

    char *table =  "p1_size | p2_size\n";

    printf("If ptr is NULL, the call is equivalent to malloc(size)\n");
    printf("%s", table);
    p_a = NULL;
    print(p_a, p_b);
    p_b = my_realloc(p_a, 6);
    print(p_a, p_b);

    printf("\nIf size is equal to zero, the call is equivalent to free(ptr)\n");
    printf("%s", table);
    p_a = (int *) my_malloc(2);
    print(p_a, p_b);
    p_b = my_realloc(p_a, 0);
    print(p_a, p_b);

    printf("\nUnless ptr is NULL\n");
    printf("%s", table);
    p_a = (int *) my_malloc(2);
    print(p_a, p_b);
    p_b = my_realloc(p_a, 6);
    print(p_a, p_b);

    my_free(p_b); // free pointer
    return (0);
}

void *my_realloc(void *p_old, size_t size) {
    if (!p_old) return my_malloc(size);
    if (!size) return (void *) my_free(p_old);
    void *p_new = my_malloc(size);
    memcpy(p_new, p_old, my_sizeof(p_old));
    my_free(p_old);
    return p_new;
}

void *my_malloc(size_t size) {
    if (!size) return (void *) NULL;
    size_t *result = (size_t *) malloc(size * sizeof(size_t));
    *result = size;
    memset(++result, 0, size);
}

void *my_free(void *ptr) {
    if (!ptr) return (void *) NULL;
    size_t *size = ptr;
    free(--size);
}

size_t my_sizeof(void *ptr) {
    if (!ptr) return (size_t) NULL;
    size_t *size = ptr;
    return *(--size);
}

void print(int *p_a, int *p_b) {
    printf("   %-5zu|    %zu\n", my_sizeof(p_a), my_sizeof(p_b));
}
