#include "mysync.h"
#include "globals.h"

LIST *list_new(void)
{
    return NULL;
}

//  DETERMINE IF A REQUIRED ITEM (A STRING) IS STORED IN A GIVEN LIST
bool list_find(LIST *list, char *wanted)
{
    while(list != NULL) {
        if(strcmp(list->filepath, wanted) == 0) {
            return true;
        }
        list	= list->next;
    }
    return false;
}

// Create a new list item with a given filepath and dirindex
LIST *list_new_item(char *new_filepath, int dirindex, long int modTime)
{
    LIST *new = calloc(1, sizeof(LIST) );
    CHECK_ALLOC(new);
    new->filepath = strdup(new_filepath);
    CHECK_ALLOC(new->filepath);
    new->dirindex = dirindex;
    new->modTime = modTime;
    new->next = NULL;
    return new;
}


// Add a new filepath to the list (if it doesn't exist) and associate it with a directory index
LIST *list_add(LIST *list, char *new_filepath, int dirindex, long int modTime)
{

    // add new item to head of list
        LIST *new = list_new_item(new_filepath, dirindex, modTime);
        new->next = list;
        return new;

}


// Print each item in the list
void list_print(LIST *list)
{
    if(list != NULL) {
        while(list != NULL) {
            printf("Filepath: %s, Dir Index: %d", list->filepath, list->dirindex);
            if(list->next != NULL) {
                printf(" -> ");
            }
            list = list->next;
        }
        printf("\n");
    }
}