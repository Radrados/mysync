#include "mysync.h"
#include "globals.h"


HASHTABLE *filesHashtable;

int main(int argc, char *argv[]) {
    int opt;
    int optcount =0;



    while ((opt = getopt(argc, argv, "vo:i:anpr")) != -1) {
        switch (opt) {
            case 'v':
                verbose = true;
                optcount++;
                break;
            case 'o':
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
                all = true;
                break;
            case 'n':
                optcount++;
                if(verbose){
                    printf("files identified, not actually synchronised\n");
                }
                notchange = true;
                verbose = true;
                break;
            case 'p':
                optcount++;
                if(verbose){
                    printf("new copy of file have same permisions as old file\n");
                }
                permisions = true;

                break;
            case 'r':
                optcount++;
                if(verbose){
                    printf("recursively process all files\n");
                }
                recursive= true;
                break;

            default: /* '?' */
                fprintf(stderr, "Usage: %s [-v] [-o arg] \n", argv[0]);
                return 1;
        }
    }
    if (verbose) {
        printf("Verbose mode enabled\n");
    }

    filesHashtable = hashtable_new();
    dircount = argc  - optcount-1;//number of directories
    indexDirs(argv, argc, dircount);
    int dirc = 0;
    for (int directory = optcount+1; directory < argc; directory++ ){
        if(verbose){
            printf("\nreading directory:%s\n", argv[directory]);//
        }
        searchDir(argv[directory]);//test
        dirc = directory-optcount;
    }

    if(verbose){
        printf("\n there are %i directories\n", dirc);
        printf("\n printing hashtable\n");
        hashtable_print(filesHashtable);

    }


    updateHash();

    return 0;
}
