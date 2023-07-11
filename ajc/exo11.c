#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE* fptr = NULL;
    char data[2];
    int cmpt = 0;
    char path[] = "ajc/file1.txt";
    char* merge = NULL;

    for( int i = 49;i < 51;i++){
        path[8] = i;
        fptr = fopen(path, "r");
        
        while (fgets(data,2, fptr)){
            merge = (char*)realloc(merge, sizeof(char) * cmpt);
            strcat(merge,data);
            cmpt ++ ;
        }

        merge = (char*)realloc(merge, sizeof(char) * cmpt);
        merge[cmpt] = ' ';
        cmpt ++;
        fclose(fptr);

    }
    merge[cmpt] = '\n';

    fptr = fopen("ajc/merge.txt", "w");

    fprintf(fptr,"%s",merge);

    fclose(fptr); 

    return 0;
}