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

void searchDir(char * directory){
    //OPEN DIRECTORY AND STORE IT IN DIR TYPE OBJECT
    DIR *dir = opendir(directory);

    //STRUCT dirent IS THE NEXT entry IN DIRECTORY WHEN YOU CALL READIR
    struct dirent *entry;

    //repeatedly get the next thing in directory
    while((entry = readdir(dir)) != NULL){

        //entry is now the next entry from dir

        //check if entry is a hiddenfile
        if(entry->d_name[0]== '.'){

            //skip if it is current or parent directory
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            vprint("\t%s is a hidden file\n", entry->d_name);
            storeFileInHash(directory, entry->d_name);
        }

        //check if entry is directory /
        else if (entry->d_type == DT_DIR) {
            vprint("\t%s is a directory.\n", entry->d_name);
        }

        //if not dir or hiden its a normal file
        else{
            vprint("\t%s is a normal file\n", entry -> d_name);
            storeFileInHash(directory, entry->d_name);

        }
    }

    //close directory
    closedir(dir);
}

void initialize_directories(char *argv[], int argc, int optcount) {
    // Find the length of the longest value in argv
    int max_len = 0;
    for (int i = 0; i < argc; i++) {
        int len = strlen(argv[i]);
        if (len > max_len) {
            max_len = len;
        }
    }

    // Allocate memory for the directories array
    directories = (char **)malloc(optcount * sizeof(char *));
    for (int i = 0; i < argc - optcount; i++) {
        directories[i] = (char *)malloc((max_len + 1) * sizeof(char));  // +1 for the null terminator
    }

    // Initialize the strings with empty strings or copy from argv
    for (int i = 0; i < optcount; i++) {
        if (i < argc) {
            strcpy(directories[i], argv[i]);
        } else {
            directories[i][0] = '\0';
        }
    }
}
