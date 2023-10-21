#include "mysync.h"
#include "globals.h"

LIST *findMostRecent(LIST *head, char *filepath) {
    // List storing the most recent element with the specified filepath
    LIST *mostRecent = NULL;

    // Traverse the list until its end
    while (head != NULL) {
        // Check if the current node has the specified filepath
        if (strcmp(head->filepath, filepath) == 0) {
            // If we haven't found a match yet or the current node's modTime is more recent, update mostRecent
            if (mostRecent == NULL || head->modTime > mostRecent->modTime) {
                mostRecent = head;
            }
        }
        // Move to the next node
        head = head->next;
    }

    return mostRecent;
}
void removeFromBucket(int bucket, char *filepath) {
    // Use a pointer-to-pointer approach. This allows us to easily update
    // pointers in the list irrespective of whether we're dealing with
    // the head of the list or a node in the middle.
    // At the start, current_ref points to the beginning of the list at the specified bucket.
    LIST **current_ref = &filesHashtable[bucket];

    // Traverse the list for the specified bucket
    while (*current_ref != NULL) {
        // If the filepath of the current node matches the given filepath
        if (strcmp((*current_ref)->filepath, filepath) == 0) {
            //store the node that needs to be removed in node_to_remove
//            LIST *node_to_remove = *current_ref;
            // Update the pointer (could be the head of the list or a 'next' pointer of a node)
            // to skip the node that's being removed and point to the next node
            *current_ref = (*current_ref)->next;
        } else {
            // If the filepath of the current node doesn't match the given filepath,
            // move to the next node in the list by updating current_ref to point to the 'next' pointer of the current node.
            current_ref = &(*current_ref)->next;
        }
    }
}
void syncHash(){
    //filepath, new mod-date, new dir, for every bucket in hashfile
    for(int bucket =0; bucket< HASHTABLE_SIZE; bucket++) {

        //current is the first item in bucket
        LIST *current = filesHashtable[bucket];

        //while bucket not empty
        while(current != NULL){

            //find most recent file with same filepath as currentnode
            LIST *mostRecent = findMostRecent(filesHashtable[bucket], current -> filepath);

            //print mostrecentnode
            if(!notchange){
                updateFile(mostRecent->filepath, mostRecent->dirindex);
            }
            else{
                vprint("~~~~~~~~~~~~~file to be copied it %s in %s modtime: %li\n", mostRecent->filepath, directories[mostRecent->dirindex], mostRecent->modTime);

            }

            //remove all nodes with same filepath as current but the newest node from bucket
            vprint("removing %s froem bucket\n", current->filepath);
            removeFromBucket(bucket, current->filepath);

            //reset current
            current = filesHashtable[bucket];

        }
    }
}