//
// Created by RadRados on 19/10/2023.
//
#include "globals.h"
#include "mysync1.h"
#define BUFER_SIZE      1024

char *combinefilepath(char* directory, char *filepath){
    // +2 for the slash and null-terminator
    char *totalpath = malloc(strlen(directory) + strlen(filepath) + 2);

    sprintf(totalpath, "%s/%s", directory, filepath);
    return totalpath;
}

// Stores file in a hash table
void storeFileInHash(char *directory, char *filepath){

    //variable to store combined filepath
    char totalpath[strlen(directory)+ strlen(filepath)+2];

    //combine dir and filepath into totalpath
    sprintf(totalpath, "%s/%s", directory, filepath);

    //get modtime
    struct stat file_stat;
    long int modTime;

    if (stat(totalpath, &file_stat) == -1){
        perror("geting file stat error");
    }
    
    //get last mod time
    modTime = (long int)file_stat.st_mtime;

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

// function used to copy file
void copyfile(char *filetocopy, char *destinationdirectory){

    FILE *source;
    FILE *destination;

    size_t bytesRead;

    char buffer[BUFER_SIZE];

    //open source file with read permissions
    source = fopen(filetocopy, "rb");

    destination = fopen(destinationdirectory, "wb");

    //check fileopening
    if(source==NULL){
        vprint("unnable to open source file: %s\n", source);
    }

    //check fileopening
    if(destination==NULL){
        vprint("unnable to open dest file: %s\n", source);
    }

    // Copy the file content from source to destination using chunks
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    //close files
    fclose(source);
    fclose(destination);

    // to hold the file attributes
    struct stat fileStat;




    //if permisons are there, change them in destination file
    if (permisions) {

        if(stat(filetocopy, &fileStat)==-1){
            perror("stat");
        }

        // set the permissions of the destination file

        chmod(destinationdirectory, fileStat.st_mode);

        //set the modification time of the destination file
        struct utimbuf new_times;
        // access time
        new_times.actime = fileStat.st_atime;
        // mod time
        new_times.modtime = fileStat.st_mtime;
        utime(destinationdirectory, &new_times);
    }
}

// updates files that need updating
void updateFile(char *filename, int dirindex){

    //find totalpath of most up to date file
    char *sourcefilepath;

    sourcefilepath = combinefilepath(directories[dirindex], filename);

    //for each directory except dirindex
    for(int i = 0; i< dircount; i ++){

        //if dir isnts dirindex
        if (dirindex != i) {

            //copy filename into it
            copyfile(sourcefilepath, combinefilepath(directories[i], filename));
        }
    }
}

























