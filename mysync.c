#include "mysync.h"

int verbose = 0;  // Global verbose flag
char *only;
char *ignore;

int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "vo:i:anpr")) != -1) {
        switch (opt) {
            case 'v':
                verbose = 1;
                break;
            case 'o':
                only = optarg;
                if(verbose){
                    printf("only synching files that constain %s\n", only);
                }
                break;
            case 'i':
                ignore = optarg;
                if(verbose){
                    printf("only synching files that constain %s\n", ignore);
                }
                break;
            case 'a':
                if(verbose){
                    printf("synchronizing all files\n");
                }
                break;
            case 'n':
                if(verbose){
                    printf("files identified, not actually synchronised\n");
                }
                break;
            case 'p':
                if(verbose){
                    printf("new copy of file have same permisions as old file\n");
                }
                break;
            case 'r':
                if(verbose){
                    printf("recursively process all files\n");
                }
                break;

            default: /* '?' */
                fprintf(stderr, "Usage: %s [-v] [-o arg] \n", argv[0]);
                return 1;
        }
    }

    if (verbose) {
        printf("Verbose mode enabled\n");
    }

    return 0;
}
