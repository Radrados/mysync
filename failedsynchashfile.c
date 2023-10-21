#include "mysync1.h"
#include "globals.h"


// Peek at the first item in the list
LIST* list_peek(LIST *list) {
    return list;
}

// grab the most recent file
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

    // Handle the rest of the list
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
    // return the potentially new head of the list
    return list;
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