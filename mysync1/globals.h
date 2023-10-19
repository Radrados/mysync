//
// Created by RadRados on 19/10/2023.
//

#ifndef MYSYNC_GLOBALS_H
#define MYSYNC_GLOBALS_H

#include "mysync1.h"
//OPTIONS
extern int verbose;
extern bool all;
extern bool recursive;
extern bool notchange;
extern bool permisions;
extern char *only;
extern char *ignore;

//STORE DIRECTORY INFO
extern int dircount;
extern char **directories;

// OUR SIMPLE LIST DATATYPE - A DATA ITEM, AND A POINTER TO ANOTHER LIST
typedef struct _list {
    char *filepath;   // filepath excluding the first directoru
    int dirindex;  // to store the directory index
    struct _list *next;
} LIST;


#endif //MYSYNC_GLOBALS_H
