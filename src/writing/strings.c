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

    orig[i+1] = 'c';
    orig[i+2] = 'o';
    orig[i+3] = 'm';
    orig[i+4] = 'p';
    orig[i+5] = 'r';
    orig[i+6] = 'e';
    orig[i+7] = 's';
    orig[i+8] = 's';
    orig[i+9] = 'e';
    orig[i+10] = 'd';

    int u = i + 11 , c = 0;
    for(;extension[c]!='\0';c++,u++) orig[u] = extension[c];
    orig[u+c] = extension[c];
}