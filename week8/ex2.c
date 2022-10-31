#include <malloc.h>
#include <memory.h>
#include <unistd.h>
#include <time.h>

/* ex2.c
    If swap is off, the OS kills my program when all free memory is allocated.
    If I add swap, after all physical memory has been allocated, it uses swap
    and "si" and "so" fields are greater than 0. But there are often tricks to
    freeze using swap, since the memory for important operating system programs
    is copied to swap. And the hard drive is too slow.
 */


/* ex3.c
    Result displays all the memory of our process
    and see that the swap memory is too slow.
 */

int main() {
    time_t begin, end;
    size_t size = 10 * 1024 * 1024;
    time(&begin);
    while (difftime(end, begin) < 10.0) {
        int *arr = (int *) malloc(size);
        memset(arr, 0, size);
        sleep(1);
        time(&end);
    }
    return 0;
}
