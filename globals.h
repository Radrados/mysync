// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H
#include <stdbool.h>

// Forward declaration of LIST
struct _list;
typedef struct _list LIST;

// Define HASHTABLE as a pointer to LIST based on the forward declaration
typedef LIST *HASHTABLE;

// Declare the global variable

extern int verbose;
extern bool all;
extern bool recursive;
extern bool notchange;
extern bool permisions;
extern char *only;
extern char *ignore;


extern HASHTABLE *filesHashtable;


#endif  // GLOBALS_H
