//
// Created by RadRados on 16/10/2023.
//
//
// Created by RadRados on 16/10/2023.
//
#include "mysync.h"
#include "globals.h"

void searchDir(const char *dirname) {
    struct dirent *file;
    DIR *dir;

    dir = opendir(dirname);
    if (dir == NULL) {
        printf("can not open directory %s\n", dirname);
        return;
    }

    while ((file = readdir(dir)) != NULL) {
        if (file->d_type == DT_DIR) {//if it is a directory

            if(recursive && strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0) {

                if (verbose){
                    printf("\t%s is a directory.\n", file->d_name);

                }//! searchDir(file);
//                char new_path[1024];
//                snprintf(new_path, sizeof(new_path), "%s/%s", dirname, file->d_name);
//                searchDir(new_path);
            } else{
                continue;
            }
        }
        else if (file->d_name[0] == '.') {// is it a hidden file
            if(verbose){
                printf("\t%s is a hidden file.\n", file->d_name);

            }
            if(all){//if -a is selected
                hashtable_add(&filesHashtable, file->d_name,dirname );//add hidden file to directory and the dirrectory it is in
            } else{
                continue;
            }
        }else {
            printf("\t%s is a normal file.\n", file->d_name);
            printf("segfaulttest\n");
            hashtable_add(&filesHashtable, file->d_name,
                          dirname);//add normal file to directory and the dirrectory it is in
            printf("segfaulttes2\n");
        }

    }

    closedir(dir);
}
void indexDirs(char *argv[], int argc, int dircount){

    int max_length = 0;

    // Find the maximum length in argv
    for(int i = 0; i < argc; i++){
        int current_length = strlen(argv[i]);
        if(current_length > max_length){
            max_length = current_length;
        }
    }

    directories = malloc(dircount * sizeof(char *));
    if(!directories){
        printf("error allocating memeory for directories array\n");
    }
    // Allocate memory for each individual string and copy from argv
    for(int argument = 0; argument < dircount; argument++){
        directories[argument] = malloc((max_length + 1) * sizeof(char)); // +1 for null terminator
        if (!directories[argument]) {
            printf("error allocating memory for directory string\n");
            return;
        }
        strcpy(directories[argument], argv[argument + (argc - dircount)]);
        printf("~~%s", directories[argument]);
    }


}
