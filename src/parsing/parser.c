#include "parser.h"

#define LINE_MAX 2048
#define MAX_SYMBOLS 256



/*Translates what we have read from each line to actual meaningful information to latter use for 
compression.*/
void info_parser(char symbols[MAX_SYMBOLS], CompressInfo * file_info){
    for(int i = 0 ; i < MAX_SYMBOLS ; i++){
        
    }
}


/* Reads each individual file line incrementing symbols array on its respective index ,
 for each time an symbol is seen.*/
void lineParser(char line[LINE_MAX] , char symbols[MAX_SYMBOLS] , CompressInfo * file_info){
    for(int i=0; line[i] != '\n' ; i++){
        symbols[line[i]]++;
    }
}

/* Parses the file reading each symbol and its probability , returns 1 on SUCESS if path exists and 0 
on fail , aka the file path doesnt return any actual file.*/
int parseArguments(char * path , CompressInfo * file_info){
    FILE * file = fopen(path,"r");
    if(file == NULL) return 0;
    file_info->file = file;

    char symbols[MAX_SYMBOLS] = {0} , line[LINE_MAX];
    while(fgets(line,LINE_MAX,file)){
        lineParser(line,symbols,file_info);
    }
    info_parser(symbols,file_info);
    return 1;
}