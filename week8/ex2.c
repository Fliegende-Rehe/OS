#include <malloc.h>
#include <memory.h>
#include <unistd.h>
#include <time.h>

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
