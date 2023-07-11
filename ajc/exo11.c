#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE* fptr = NULL;
    char c;
    FILE* mergeptr = fopen("ajc/merge.txt", "w");

    for( int i = 1;i < argc;i++){
        fptr = fopen(argv[i], "r");
        
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