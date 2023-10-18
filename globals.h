// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

// Forward declaration of LIST
struct _list;
typedef struct _list LIST;

// Define HASHTABLE as a pointer to LIST based on the forward declaration
typedef LIST *HASHTABLE;

// Declare the global variable
extern HASHTABLE filesHashtable;

extern int verbose;
extern char *ignore;
extern char *only;

#endif  // GLOBALS_H
