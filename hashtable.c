#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "mysync.h"

//  RESEARCH SHOWS THAT USING PRIME-NUMBERS CAN IMPROVE PERFORMANCE
//  c.f.  https://www.quora.com/Why-should-the-size-of-a-hash-table-be-a-prime-number
#define	HASHTABLE_SIZE		997

//  --------------------------------------------------------------------

//  FUNCTION hash_string() ACCEPTS A STRING PARAMETER,
//  AND RETURNS AN UNSIGNED 32-BIT INTEGER AS ITS RESULT
//
//  see:  https://en.cppreference.com/w/c/types/integer

uint32_t hash_string(char *string)
{
    uint32_t hash = 0;

    while(*string != '\0') {
        hash = hash*33 + *string;
        ++string;
    }
    return hash;
}

//  ALLOCATE AND INITIALISE SPACE FOR A NEW HASHTABLE (AN ARRAY OF LISTS)
HASHTABLE *hashtable_new(void)
{
    HASHTABLE   *new = calloc(HASHTABLE_SIZE, sizeof(LIST *));

    CHECK_ALLOC(new);
    return new;
}

//  ADD A NEW STRING TO A GIVEN HASHTABLE
void hashtable_add(HASHTABLE *hashtable, char *filename, const char *directory)
{
    uint32_t h   = hash_string(filename) % HASHTABLE_SIZE;    // choose list

    hashtable[h] = list_add(hashtable[h], filename, directory);
}

//  DETERMINE IF A REQUIRED STRING ALREADY EXISTS IN A GIVEN HASHTABLE
bool hashtable_find(HASHTABLE *hashtable, char *string)
{
    uint32_t h	= hash_string(string) % HASHTABLE_SIZE;     // choose list

    return list_find(hashtable[h], string);
}
void hashtable_print(HASHTABLE *hashtable) {
    for (int i = 0; i < HASHTABLE_SIZE; i++) {
        LIST *current_list = hashtable[i];
        if (current_list) { // Check if the bucket is not empty
            printf("Bucket %d:\n", i); // Print the bucket number
            while (current_list) {
                printf("\tDirectory: %s, Filename: %s\n", current_list->directory, current_list->filename);
                current_list = current_list->next;
            }
            printf("\n"); // For better readability between buckets
        }
    }
}
