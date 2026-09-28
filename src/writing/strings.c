#include <stdio.h>
#include <stdlib.h>

int strlent(char * str){
    int i=0;
    for(;str[i]!='\0';i++);
    return i;
}


void append_compressed(char *orig){
    if(orig == NULL) return;
    int i=0 , j = 0;

    for(;orig[i]!='.';i++);

    char extension[256];
    for(j=i+1;orig[j]!='\0';j++) extension[j-i-1] = orig[j];
    extension[j-i-1] = '\0';

    orig[i+1] = '_';
    orig[i+2] = 'z';
    orig[i+3] = 'i';
    orig[i+4] = 'p';

    int u = i + 4 , c = 0;
    for(;extension[c]!='\0';c++,u++) orig[u] = extension[c];
    orig[u+c] = extension[c];
}