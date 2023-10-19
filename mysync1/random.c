//
// Created by RadRados on 19/10/2023.
//
#include "mysync.h"
#include "globals.h"

void vprint(const char *fmt, ...) {
    if(verbose) {
        va_list args;
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);
    }
}