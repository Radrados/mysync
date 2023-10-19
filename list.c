#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mysync.h"

//  ON LINUX WE NEED TO PROTOTYPE THE (NON-STANDARD) strdup() FUNCTION 
//  WHY?  https://stackoverflow.com/questions/32944390/what-is-the-rationale-for-not-including-strdup-in-the-c-standard

#if	defined(__linux__)
extern	char	*strdup(char *string);
#endif

//  ---------------------------------------------------------------------

//  'CREATE' A NEW, EMPTY LIST - JUST A NULL POINTER
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

LIST* list_pop(LIST **head) {
    if (*head == NULL) {
        return NULL;  // Return NULL if list is empty
    }

    // Save the head item
    LIST *popped_item = *head;

    // Move the head pointer to the next item
    *head = (*head)->next;

    // Remove 'next' link from the popped item to fully detach it from the list
    popped_item->next = NULL;

    return popped_item;
}

LIST* list_peek(LIST **head) {
    if (*head == NULL) {
        return NULL;  // Return NULL if list is empty
    }
    printf("segfaulttest peektest\n");


    // Save the head item
    LIST *popped_item = *head;
    printf("segfaulttest peektest2\n");

    return popped_item;
}

//  ALLOCATE SPACE FOR A NEW LIST ITEM, TESTING THAT ALLOCATION SUCCEEDS
LIST *list_new_item(char *filepath, int dirindex)
{
    LIST *new       = calloc(1, sizeof(LIST) );
    CHECK_ALLOC(new);
    new->filepath     =  strdup(filepath);
    new ->dirindex = dirindex;

    CHECK_ALLOC(new->filepath);
//    CHECK_ALLOC(new->dirindex);


    new->next       =  NULL;
    return new;
}

//  ADD A NEW (STRING) ITEM TO AN EXISTING LIST
LIST *list_add(LIST *list, char *filepath, int dirindex)
{


    //calculate dir index if exists add new if not
    //add filepath to list, add index to list
    printf("segfaulttest9.1\n");
    LIST *new   = list_new_item(filepath, dirindex);
    printf("segfaulttest9.2\n");
    new->next   = list;
    printf("segfaulttest9.3\n");
    return new;
}

//  PRINT EACH ITEM (A STRING) IN A GIVEN LIST TO stdout
void list_print(LIST *list)
{
    if(list != NULL) {
        while(list != NULL) {
            printf("filepath: %s, directory index: %i", list->filepath, list->dirindex);
            if(list->next != NULL) {
                printf(" -> ");
                }
            list	= list->next;
        }
        printf("\n");
    }
}
