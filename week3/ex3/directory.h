#include "file.h"

struct Directory {
    struct File files[256];
    int nf;
    int nd;
    char path[256];
    struct Directory* directories[256];
};

void add_file(struct File* file, struct Directory* dir) {

}