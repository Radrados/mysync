//
// Created by RadRados on 19/10/2023.
//
#include "mysync1.h"
#include "globals.h"

uint32_t hash_string(char *filepath)
{
    uint32_t hash = 0;

    while(*filepath != '\0') {
        hash = hash*33 + *filepath;
        ++filepath;
    }
    return hash;
}
void hashtable_initialize(void)
{
    for(int i = 0; i < HASHTABLE_SIZE; i++)
    {
        filesHashtable[i] = NULL;
    }
}

// Add a new filepath and dirindex to the global filesHashtable
void hashtable_add(char *filepath, int dirindex)
{
    uint32_t h = hash_string(filepath) % HASHTABLE_SIZE;  // choose list
    filesHashtable[h] = list_add(filesHashtable[h], filepath, dirindex);
}

// Determine if a required filepath already exists in the global filesHashtable
bool hashtable_find(char *filepath)
{
    uint32_t h = hash_string(filepath) % HASHTABLE_SIZE;  // choose list
    return list_find(filesHashtable[h], filepath);
}



void hashtable_print(void)
{
    printf("=== Files Hashtable ===\n");

    for (uint32_t i = 0; i < HASHTABLE_SIZE; i++)
    {
        LIST *current = filesHashtable[i];
        printf("Bucket %u: ", i);

        while (current != NULL)
        {
            printf("{ filepath: %s, dirindex: %d }", current->filepath, current->dirindex);
            current = current->next;
            if (current != NULL)
            {
                printf(" -> ");
            }
        }
        printf("\n");
    }
}
