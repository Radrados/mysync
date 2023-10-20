//
// Created by RadRados on 19/10/2023.
//
#include "globals.h"
#include "mysync1.h"

char *combinefilepath(char* directory, char *fileapth){
    printf("SFASFSa%s%s", directory, fileapth);
    return directory;
}

void storeFileInHash(char *directory, char *filepath){

    //variable to store fombined filepath
    char totalpath[strlen(directory)+ strlen(filepath)+2];

    //combine dir and filepath into totalpath
    sprintf(totalpath, "%s/%s", directory, filepath);

    //get modtime
    struct stat file_stat;
    long int modTime;

    if (stat(totalpath, &file_stat) == -1){
        perror("geting file stat error");
    }

    modTime = (long int)file_stat.st_mtime;//get last mod time

    vprint("\t\tstoring %s/%s in hashtabe\n", directory, filepath)
;
    //index of directory in global var directories
    int dirindex = -1;

    for(int i = 0; i < dircount; i++){
        if(strcmp(directory, directories[i])==0){
            dirindex = i;
        }
    }

    hashtable_add(filepath, dirindex, modTime);
}