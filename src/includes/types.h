#include <stdio.h>

typedef struct CompressInfo{
    FILE * file;
    int n_symbols;
    char * symbols;
    float * probabilities;
    unsigned long long * new_symbols;
    int last_max_bits;
    int new_max_bits;
}CompressInfo;