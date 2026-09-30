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

    for(;orig[i]!='.' && orig[i]!='\0';i++) dest[i] = orig[i];
    dest[i] = '_';
    dest[i+1] = 'z';
    dest[i+2] = 'i';
    dest[i+3] = 'p';

    for(j=i+4;orig[i]!='\0';j++,i++) dest[j] = orig[i];
    dest[j] = '\0';
}