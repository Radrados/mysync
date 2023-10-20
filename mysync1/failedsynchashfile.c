//
// Created by RadRados on 20/10/2023.
//
//
// Created by RadRados on 19/10/2023.
//
#include "mysync1.h"
#include "globals.h"


// Peek at the first item in the list
LIST* list_peek(LIST *list) {
    return list; // simply return the head of the list
}
LIST *findMostRecent(LIST* list, char *wanted) {
    LIST *mostrecent = NULL;

    while(list != NULL) {
        if(strcmp(list->filepath, wanted) == 0) {
            if (!mostrecent || list->modTime > mostrecent->modTime) {
                mostrecent = list;
            }
        }
        list = list->next;
    }
    return mostrecent;
}

LIST* removeFilepathFromList(char *filepath, LIST *list) {
    if (!filepath || !list) {
        return list;
    }

    // Handle the head of the list separately
    while (list && strcmp(list->filepath, filepath) == 0) {
        LIST *temp = list;
        list = list->next;
        free(temp->filepath);
        free(temp);
    }

    // Now handle the rest of the list
    LIST *current = list;
    while (current && current->next) {
        if (strcmp(current->next->filepath, filepath) == 0) {
            LIST *temp = current->next;
            current->next = current->next->next;
            free(temp->filepath);
            free(temp);
        } else {
            current = current->next;
        }
    }

    return list;  // Return the potentially new head of the list
}

void syncHash() {
    LIST *current;

    // For each bucket
    for (int bucket = 0; bucket < HASHTABLE_SIZE; bucket++) {
        // Find the most recent version for each filepath
        current = filesHashtable[bucket];
        while (current != NULL) {
            // Identify the most recent node for the current filepath
            LIST *mostRecent = findMostRecent(filesHashtable[bucket], current->filepath);
            vprint("\t~~~~~~~~newest file is %s %i %li\n", mostRecent->filepath, mostRecent->dirindex, mostRecent->modTime);

            // Remove all nodes with the current filepath
            filesHashtable[bucket] = removeFilepathFromList(current->filepath, filesHashtable[bucket]);

            // Start the iteration again since the structure might have changed
            current = filesHashtable[bucket];
        }
    }
}

//
//
//void syncHash(){
////
////    int mostRecentDir=-1;
////    long int mostRecentUpdate = -1;
//    char filepath [256];
//    LIST *current;
//    LIST *temp;
//
//    //for each bucket
//    for(int bucket = 0; bucket < HASHTABLE_SIZE; bucket++){
//
//        //assing first element of bucket to current
//        current = list_peek(filesHashtable[bucket]);
//
//        //while tthere are items in bucket
//        while(current != NULL) {
//
//
//
//            //find most recent
//            temp = findMostRecent(filesHashtable[bucket], current->filepath);//make sure to send pointers so you can update them
//            vprint("\t~~~~~~~~newest file is %s %i %li\n", temp->filepath, temp->dirindex, temp->modTime);
//
//            //remove all instanves of that filepath
//            removeFilepathFromList( filepath, filesHashtable[bucket]);
//
//            //move on to next item in the list
//            current = current->next;
//
//        }
//    }
//
//
//    //for each filepath
//
//    //find newest/only
//
//    //copy shit
//}