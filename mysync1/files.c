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

    //index of directory in global var directories
    int dirindex;

    for(int i = 0; i < dircount; i++){
        if(strcmp(directory, directories[1])==0){
            dirindex = i;
        }
    }

    hashtable_add(filepath, dirindex);
}