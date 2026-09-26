#include "parser.h"

#define LINE_MAX 2048
#define MAX_SYMBOLS 256




/* Passes the symbols of the file to an array of symbols */
void assertSymbols(char * orig , int number_s , char * dest){
    for(int i = 0 ; i < number_s ; i++){
        *(dest + i) = *(orig + i);
    }
}

/*Calculates the probability of each symbol appearing on the file.*/
void assertProbabilities(int * freq , int number_s , float * dest){
    float total = (float)number_s;
    for(int i=0 ; i < number_s ; i++){
        dest[i] = (float)freq[i] / total;
    }
}

/* Asserts the max amount of bits necessary to write the longest symbol of the file.*/
void assertMaxBits(char * file_symbols , int number_s , int * max_bits){
    int asserter = file_symbols[number_s - 1];
    int bits = 1;
    while(asserter > 0){
        asserter = asserter / 10;
        bits++;
    }
    *max_bits = bits;
}


/*Translates what we have read from each line to actual meaningful information to latter use for 
compression.*/
void info_parser(int symbols[MAX_SYMBOLS], CompressInfo * file_info){
    int number_symbols = 0;
    char file_symbols[256];
    int freq_symbols[256];
    for(int i = 0 ; i < MAX_SYMBOLS ; i++){
        if(symbols[i]){
            file_symbols[number_symbols] = i;
            freq_symbols[number_symbols] = symbols[i];
            number_symbols++;
        }
    }

    file_info->n_symbols = number_symbols;
    file_info->symbols = malloc(sizeof(char)*number_symbols);
    file_info->probabilities = malloc(sizeof(float)*number_symbols);
    
    assertSymbols(file_symbols,number_symbols,file_info->symbols);
    assertProbabilities(freq_symbols,number_symbols,file_info->probabilities);
    assertMaxBits(file_symbols,number_symbols,&file_info->last_max_bits);
}


/* Reads each individual file line incrementing symbols array on its respective index ,
 for each time an symbol is seen.*/
void lineParser(char line[LINE_MAX] , int symbols[MAX_SYMBOLS] , CompressInfo * file_info){
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

    int symbols[MAX_SYMBOLS] = {0};
    char line[LINE_MAX];

    while(fgets(line,LINE_MAX,file)){
        lineParser(line,symbols,file_info);
    }
    info_parser(symbols,file_info);
    return 1;
}