#include "mysync.h"
int main(int argc, char *argv[]) {
    int verbose = 0;

    // Check for -v flag among the command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
            break;
        }
    }

    if (verbose) {
        printf("Verbose mode enabled.\n");

    } else {
        printf("Verbose mode disabled.\n");
    }

    return 0;
}
