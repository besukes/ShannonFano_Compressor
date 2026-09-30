#include "init_clean.h"

/* Initializes the compression information structure */
CompressInfo init_compress_info(void){
    CompressInfo c;
    c.file = NULL;
    c.last_max_bits = 0;
    c.n_symbols = 0;
    c.total_symbols = 0;
    c.new_max_bits = 0;
    c.new_symbols = NULL;
    c.probabilities = NULL;
    c.symbols = NULL;
    c.file_path = NULL;
    return c;
}

/* Frees the memory used for the compression*/
void free_memory(CompressInfo * c){
    free(c->symbols);
    free(c->probabilities);
    free(c->new_symbols);
}