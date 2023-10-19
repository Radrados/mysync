//
// Created by RadRados on 19/10/2023.
//

#ifndef MYSYNC_GLOBALS_H
#define MYSYNC_GLOBALS_H

#include "mysync1.h"
//OPTIONS
extern bool  verbose;
extern bool all;
extern bool recursive;
extern bool notchange;
extern bool permisions;
extern char *only;
extern char *ignore;

//STORE DIRECTORY INFO
extern int dircount;
extern char **directories;

extern void initialize_globals();




#endif //MYSYNC_GLOBALS_H
