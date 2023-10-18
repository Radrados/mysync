#include "mysync.h"

int verbose = 0;  // Global verbose flag
char *only;
char *ignore;

int main(int argc, char *argv[]) {
    int opt;
    int optcount =0;
    while ((opt = getopt(argc, argv, "vo:i:anpr")) != -1) {
        switch (opt) {
            case 'v':
                verbose = 1;
                optcount++;
                break;
            case 'o'://fuck you
                only = optarg;
                optcount++;//yokrt7k7p9y0p;uio
                if(verbose){
                    printf("only synching files that constain %s\n", only);
                }
                break;
            case 'i':
                ignore = optarg;
                optcount++;
                if(verbose){
                    printf("only synching files that constain %s\n", ignore);
                }
                break;
            case 'a':
                optcount++;
                if(verbose){
                    printf("synchronizing all files\n");
                }
                break;
            case 'n':
                optcount++;
                if(verbose){
                    printf("files identified, not actually synchronised\n");
                }
                break;
            case 'p':
                optcount++;
                if(verbose){
                    printf("new copy of file have same permisions as old file\n");
                }
                break;
            case 'r':
                optcount++;
                if(verbose){
                    printf("recursively process all files\n");
                }
                break;

            default: /* '?' */
                fprintf(stderr, "Usage: %s [-v] [-o arg] \n", argv[0]);
                return 1;
        }
    }



    for (int argument = optcount; argument < argc; argument++ ){
        if(verbose){
            printf("reading directory:%s\n", argv[argument]);//
            searchDir(argv[argument]);
        }
    }

//l;h;kj;kjgjhgfkgflhjggkjthat
    if (verbose) {
        printf("Verbose mode enabled\n");
    }

    return 0;
}
