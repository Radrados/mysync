//
// Created by RadRados on 16/10/2023.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#include <time.h>

int main(int argc, char *argv[]) {

    scan_directory(argv[1]);

}

void scanDirectory(char *dirname)
{
    DIR *dirp;
    struct dirent   *dp;

    dirp       = opendir(dirname);
    if(dirp == NULL) {
        perror(dirname);
        exit(EXIT_FAILURE);
    }

    while((dp = readdir(dirp)) != NULL) {  
        struct stat sbuffer;
        stat(dp->d_name, &sbuffer);

        char *timestr = ctime(&sbuffer.st_mtime);
        timestr[24] = '\0';
        printf( "%s\t%s\n ", timestr+4, dp->d_name );
    }
    closedir(dirp);
}
