#include <stdio.h>
#include <stdlib.h>

/* Structure to hold information about the file being compressed */
typedef struct CompressInfo{
    FILE * file; //Pointer to the file that is being compressed
    char * file_path; //Stores the file path 
    int n_symbols; //Number of symbols in the file
    char * symbols; //Array of symbols in the file
    float * probabilities; //Array of probabilities of each symbol that resides in the file
    unsigned long long * new_symbols; //Array of new bit sequences that represent the symbols in the file
    int last_max_bits; //The maximum number of bits that the symbols in the file had before compression
    int new_max_bits; //The maximum number of bits that the symbols in the file have after compression
}CompressInfo;