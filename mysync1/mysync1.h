//
// Created by RadRados on 19/10/2023.
//

#ifndef MYSYNC_MYSYNC1_H
#define MYSYNC_MYSYNC1_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#define CHECK_ALLOC(p) if(p == NULL) { perror(__func__); exit(EXIT_FAILURE); }


extern void vprint(const char *fmt, ...);

extern int usage();

extern bool canOpenDir(char * directory);

extern void searchDir(char * directory);

// OUR SIMPLE LIST DATATYPE - A DATA ITEM, AND A POINTER TO ANOTHER LIST
typedef struct _list {
    char *filepath;   // filepath excluding the first directoru
    int dirindex;  // to store the directory index
    long int modTime; // to store the time since 1970 it was last modded
    struct _list *next;
} LIST;


// THESE FUNCTIONS ARE DECLARED HERE, AND DEFINED IN list.c:

// 'CREATE' A NEW, EMPTY LIST
extern LIST *list_new(void);

extern LIST *list_pop(LIST **list);

extern LIST *list_peek(LIST **list);

// ADD A NEW (STRING) ITEM TO AN EXISTING LIST
extern LIST *list_add(LIST *list, char *filepath, int dirindex, long int modTime);

// DETERMINE IF A REQUIRED ITEM (A STRING) IS STORED IN A GIVEN LIST
extern bool list_find(LIST *list, char *wanted);

// PRINT EACH ITEM (A STRING) IN A GIVEN LIST TO stdout
extern void list_print(LIST *list);

// WE DEFINE A HASHTABLE AS A (WILL BE, DYNAMICALLY ALLOCATED) ARRAY OF LISTs
typedef LIST * HASHTABLE;

// THESE FUNCTIONS ARE DECLARED HERE, AND DEFINED IN hashtable.c :
#define	HASHTABLE_SIZE		997

//global hashtable
extern LIST *filesHashtable[HASHTABLE_SIZE];


// ALLOCATE SPACE FOR A NEW HASHTABLE (AND ARRAY OF LISTS)
extern void hashtable_initialize(void);

extern void storeFileInHash(char *directory, char *filepath);


// ADD A NEW STRING TO A GIVEN HASHTABLE
extern void hashtable_add( char *filepath, int directory, long int modTime);

// DETERMINE IF A REQUIRED STRING ALREADY EXISTS IN A GIVEN HASHTABLE
extern bool hashtable_find(char *string);

// Prints all the contents of the hashtable
extern void hashtable_print();

extern void initialize_directories(char *argv[], int argc, int optcount) ;




#endif //MYSYNC_MYSYNC1_H
