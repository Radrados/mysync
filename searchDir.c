//
// Created by RadRados on 16/10/2023.
//
#include "mysync.h"


void searchDir(const char *dirname) {
    struct dirent *entry;
    DIR *dir;

    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // Check if it's a regular file
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

