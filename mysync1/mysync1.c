//
// Created by RadRados on 19/10/2023.
//
#include "mysync1.h"
#include "globals.h"

int main(int argc, char *argv[]){

    //NUMBER OF OPTIONS
    int optcount=0;

    //OPTIONS
    int opt;
    initialize_globals();

    //LOOP THROUGH EVERY OPTION
    while((opt = getopt(argc, argv, "vprnai:o:")) != -1){// while there are oprions left

        switch(opt){

            case 'v'://VERBOSE OPTION
                verbose = true;
                optcount++;
                break;

            case 'r'://RECURSIVE OPTION
                recursive = true;
                optcount++;
                break;

            case 'a'://INCLUDE HIDDEN FILEL
                all = true;
                optcount++;
                break;

            case 'p'://COPY PERMISIONS OVER TOO
                permisions = true;
                optcount++;
                break;

            case 'n'://DO   NOT CHANGE PERMISIONS, SET VERBOSE
                notchange = true;
                verbose = true;
                optcount++;
                break;

            default: /* '?' */
                usage();
                break;
        }
    }

    vprint("Verbose mode active\n");
    if(all){
        vprint("Hidden files mode active\n");
    }
    if (permisions){
        vprint("permisions transfer mode active\n");
    }
    vprint("number of options: %i\n\n", optcount);



    /////////////////////start////////////////////////////

    //initialize fileshasthable
    hashtable_initialize();
    initialize_directories(argv, argc, optcount);

    //for each directory fed to program
    for(int argument = optcount+1; argument <  argc; argument++){

        //if can not open directory
        if(!canOpenDir(argv[argument])){

            printf("Can not open directory %s\n", argv[argument]);

        }else{//it can open directory

            dircount++;

            vprint("searching directory: %s\n", argv[argument]);
            directories[argument-optcount-1]= argv[argument];

            //search directory
            searchDir(argv[argument]);
        }

    }




    vprint("\n");
    printf(">>>>>>>>end>>>>>>>>\n");



    return 0;

}