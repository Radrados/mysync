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
        if(strcmp(list->filename, wanted) == 0) {
            return true;
        }
        list	= list->next;
        }
    return false;
}

//  ALLOCATE SPACE FOR A NEW LIST ITEM, TESTING THAT ALLOCATION SUCCEEDS
LIST *list_new_item(char *newFilename, const char *newDirectory)
{
    LIST *new       = calloc(1, sizeof(LIST) );
    CHECK_ALLOC(new);
    new->filename     =  strdup(newFilename);
    new ->directory = strdup(newDirectory);

    CHECK_ALLOC(new->filename);
    CHECK_ALLOC(new->directory);


    new->next       =  NULL;
    return new;
}

//  ADD A NEW (STRING) ITEM TO AN EXISTING LIST
LIST *list_add(LIST *list, char *newfilename, const char *newdDirectory)
{
    LIST *new   = list_new_item(newfilename, newdDirectory);
    new->next   = list;
    return new;
}

//  PRINT EACH ITEM (A STRING) IN A GIVEN LIST TO stdout
void list_print(LIST *list)
{
    if(list != NULL) {
        while(list != NULL) {
            printf("Directory: %s, Filename: %s", list->directory, list->filename);
            if(list->next != NULL) {
                printf(" -> ");
                }
            list	= list->next;
        }
        printf("\n");
    }
}