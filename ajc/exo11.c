#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE* fptr = NULL;
    char c;
    int start=1,end = argc-1;
    char law1[3] = {'w'};
    char law2[3] = {'r'};

    if(argc == 5){
        start = 2;
        law1[1] = 'b';law1[2] = '\0';
        law2[1] = 'b';law2[2] = '\0';
    }



    FILE* mergeptr = fopen(argv[end], law1);

    for( int i = start;i < argc;i++){
        fptr = fopen(argv[i], law2);
        
        while ( !((c = fgetc(fptr)) == EOF)){ 
            fprintf(mergeptr,"%c",c);
        }

        fclose(fptr);
        fputs(" ",mergeptr);
    }
    fputs("\n",mergeptr);
    fclose(mergeptr);
    return 0;
}