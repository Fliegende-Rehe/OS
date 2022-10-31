#include <malloc.h>
#include <memory.h>
#include <unistd.h>
#include <time.h>
#include <sys/resource.h>

int main() {
    time_t begin, end;
    struct rusage usage;
    size_t size = 10 * 1024 * 1024;
    time(&begin);
    while (difftime(end, begin) < 10.0) {
        int *arr = (int *) malloc(size);
        memset(arr, 0, size);
        getrusage(RUSAGE_SELF, &usage);
        printf("%ld\n", usage.ru_nswap);
        sleep(1);
        time(&end);
    }
    return 0;
}
