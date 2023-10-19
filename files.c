//
// Created by RadRados on 19/10/2023.
//

#include "mysync.h"
#include "globals.h"

char *consturctFilepath(const char *directory, char *filename){
    /////sgfadf
    int totallength = strlen(directory)+ strlen(filename)+2;

    char *totalpath = (char*) malloc(totallength * sizeof (char));

    if(!totalpath){
        printf("mem alloc error concatenate path\n");
        exit(EXIT_FAILURE);
    }

    snprintf(totalpath, totallength, "%s/%s", directory, filename);


    return totalpath;
}

int findDirIndex(char *dir){
    int position = -1;
    for(int i =0; i< dircount; i++){
        if(strcmp(directories[i], dir)==0){
            position= i;
        }
    }
    if(position==-1){
        printf("shits gone wrong with directories\n\n\n\n");
    }
    return position;
}
