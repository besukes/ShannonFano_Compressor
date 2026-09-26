#include "init.h"


CompressInfo init_compress_info(void){
    CompressInfo c;
    c.file = NULL;
    c.last_max_bits = 0;
    c.n_symbols = 0;
    c.new_max_bits = 0;
    c.new_symbols = NULL;
    c.probabilities = NULL;
    c.symbols = NULL;
    return c;
}