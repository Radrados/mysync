// globals.h file

#ifndef MYSYNC_GLOBALS_H
#define MYSYNC_GLOBALS_H

#include "mysync1.h"
//OPTIONS to checkout when looking for command-line options
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

#endif