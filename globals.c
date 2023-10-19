//
// Created by RadRados on 19/10/2023.
//
//
// Created by RadRados on 19/10/2023.
//
#include "globals.h"
#include "mysync.h"


int verbose = 0;
bool all = false;
bool recursive = false;
bool notchange = false;
bool permisions = false;
char *only = NULL;
char *ignore = NULL;
int dircount = 0;
char **directories;

HASHTABLE filesHashtable;  // definition
