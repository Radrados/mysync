//
// Created by RadRados on 19/10/2023.
//
#include "mysync1.h"
#include "globals.h"

bool canOpenDir(char *dirname){
    DIR *dir = opendir(dirname);
    if (dir != NULL) {
        closedir(dir);  // Close the directory if it was opened successfully
        return 1;  // Return 1 (true) if the directory can be opened
    }
    return 0;  // Return 0 (false) if the directory cannot be opened

}