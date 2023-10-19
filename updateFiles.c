//
// Created by RadRados on 19/10/2023.
//
#include "globals.h"
#include "mysync.h"

void newest_mod_time(long int *mostRecentArr, char *filename, int bucket){
    printf("segfaulttest    newestmodtime\n");

    LIST *current = &filesHashtable[bucket];
    struct stat file_stat;
    long int mostRecentDir;

    if (stat(filename, &file_stat) != 0) {
        perror("Failed to get file status");
    }

    time_t mostRecent = file_stat.st_mtimespec.tv_sec;
    printf("current most recent is %li\n", mostRecent);
    while(current != NULL){
        //check you can get the stat from filename
        if (stat(current->filepath, &file_stat) != 0) {
            perror("Failed to get file status for list item");
        } else {
            //if current is more recent than mostrecent update morstrecent
            if (file_stat.st_mtimespec.tv_sec > mostRecent) {
                mostRecent = file_stat.st_mtimespec.tv_sec;
                mostRecentDir = current->dirindex;
            }
        }
        current = current->next;  // Move to the next item in the list
    }
    mostRecentArr[0]= mostRecent;
    mostRecentArr[1]= mostRecentDir;
}

void updateBucket(int bucket){
    printf("segfaulttest updating bucket %i\n", bucket);
    LIST *list = &filesHashtable[bucket];
    LIST currfile;
    long int mostrecent[2];

    while(list != NULL){
        printf("segfaulttest list isnt null\n");

        currfile = *list_peek(&list);
        newest_mod_time(mostrecent, currfile.filepath, bucket);//finds the modtime of the newest file with the filename of the top of the
        //mostrecent0 is the time of the most recent
        //mostrecent 1 is the dir index of the most up to date file
    }


}
void updateHash(){
    if(verbose){
        printf("UPDATING HASHTABLE\n");
    }
    printf("segfaulttest updatehash\n");
    for(int bucket = 0; bucket< HASHTABLE_SIZE; bucket++){
        updateBucket(bucket);
    }

}
