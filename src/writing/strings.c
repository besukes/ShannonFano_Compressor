#include <stdio.h>
#include <stdlib.h>

int strlent(char * str){
    int i=0;
    for(;str[i]!='\0';i++);
    return i;
}


void append_zip(char *orig,char* dest){
    if(orig == NULL) return;
    int i=0 , j = 0;

    for(;orig[i]!='.';i++) dest[i] = orig[i];
    dest[i++] = '_';
    dest[i++] = 'z';
    dest[i++] = 'i';
    dest[i++] = 'p';

    for(j=i;orig[i]!='\0';j++) dest[j] = orig[j];
    dest[j] = '\0';
}