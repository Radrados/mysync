//
// Created by RadRados on 19/10/2023.
//
#include "globals.h"
#include "mysync.h"

time_t newest_mod_time(char *filename, int bucket){
    LIST *current = filesHashtable[bucket];
    struct stat file_stat;

    if (stat(filename, &file_stat) != 0) {
        perror("Failed to get file status");
        return -1;
    }

    time_t mostRecent = file_stat.st_mtimespec.tv_sec;
    printf("current most recent is %li\n", mostRecent);
    while(current != NULL){
        //check you can get the stat from filename
        if (stat(current->filename, &file_stat) != 0) {
            perror("Failed to get file status for list item");
        } else {
            //if current is more recent than mostrecent update morstrecent
            if (file_stat.st_mtimespec.tv_sec > mostRecent) {
                mostRecent = file_stat.st_mtimespec.tv_sec;
            }
        }
        current = current->next;  // Move to the next item in the list
    }
    return mostRecent;
}

void updateBucket(int bucket){
    LIST *list = filesHashtable[bucket];
    LIST currfile;
    long int mostrecent;
    while(list != NULL){
        currfile = *list_peek(&list);
        mostrecent = newest_mod_time(currfile.filepath, bucket);//finds the modtime of the newest file with the filename of the top of the


    }


}
void updateHash(){
    if(verbose){
        printf("UPDATING HASHTABLE\n");
    }
    for(int bucket = 0; bucket< HASHTABLE_SIZE; bucket++){
        updateBucket(bucket);
    }

}
