/* This module needs to compress the files , after the algorithm , but also leave the important
details about the compresssion so it can be decompressed after when , and if , needed.
*/
#include "compressor.h"



int compressFile(CompressInfo * file_info){
    sortByProbability(file_info->symbols,file_info->probabilities,file_info->n_symbols);
    
}