#include "mysync1.h"
#include "globals.h"

void vprint(const char *fmt, ...) {
    if(verbose) {
        va_list args;
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);
    }
}

int usage(){
    fprintf(stderr, "Usage: mysync [-v] [-o arg] [-i arg] [-p] [-n] [-a] [-r] \n");
    return 1;
}