//
// Created by RadRados on 19/10/2023.
//
#include "globals.h"


bool verbose ;
bool all;
bool recursive;
bool notchange;
bool permisions;

char *only;
char *ignore;

int dircount;
char **directories;

void initialize_globals() {
    verbose = 0;
    all = false;
    recursive = false;
    notchange = false;
    permisions = false;

    only = NULL;
    ignore = NULL;

    dircount = 0;
    directories = NULL;
}

HASHTABLE filesHashtable;  // definition
