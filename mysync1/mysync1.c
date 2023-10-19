//
// Created by RadRados on 19/10/2023.
//
#include "../mysync.h"
#include "../globals.h"

int main(int argc, char *argv[]){

    //NUMBER OF OPTIONS
    int optcount=0;

    //LOOP THROUGH EVERY OPTION
    while((opt = getopt(argc, argv, "vprnai:o:")) != -1){// while there are oprions left

        switch(opt){

            case 'v'://VERBOSE OPTION
                verbose = true;
                optcount++;

            case 'r'://RECURSIVE OPTION
                recursive = true;
                optcount++;

            case 'a'://INCLUDE HIDDEN FILEL
                all = true;
                optcount++;

            case 'p'://COPY PERMISIONS OVER TOO
                permisions = true;
                optcount++;

            case 'n'://DO   NOT CHANGE PERMISIONS, SET VERBOSE
                notchange = true;
                verbose = true;
                optcount++;

            default: /* '?' */
                fprintf(stderr, "Usage: %s [-v] [-o arg] [-i arg] [-p] [-n] [-a] [-r] \n", argv[0]);
                return 1;
        }
    }

}