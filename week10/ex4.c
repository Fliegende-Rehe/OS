#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

#define DIR_SIZE 3

void readDir(char *dirName);

struct file {
    char *name;
    unsigned long inode;
} *files;

int main() {
    readDir("tmp");

    printf("File - Hard Links\n");
    char **linksName = (char **) malloc(sizeof(char *) * DIR_SIZE);
    for (int i = 0; i < DIR_SIZE; ++i) {
        int k = 0;
        for (int j = 0; j < DIR_SIZE; ++j)
            if (files[i].inode == files[j].inode)
                linksName[k++] = files[j].name;
        if (!k || k < 2) continue;
        printf("%s - ", files[i].name);
        for (int j = 0; j < k; ++j)
            printf("%s%s", linksName[j], j == k - 1 ? "\n" : ", ");
    }

    return 0;
}

void readDir(char *dirName) {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(dirName);

    if (!dir) exit(1);

    files = malloc(sizeof(struct file) * DIR_SIZE);

    for (int i = 0; (entry = readdir(dir)) != NULL && i < DIR_SIZE; i++) {
        files[i].name = entry->d_name;
        files[i].inode = entry->d_ino;
        // printf("%s - %lu\n", files[i].name, files[i].inode);
    }
    closedir(dir);
}