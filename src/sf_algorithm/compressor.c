/* This module needs to compress the files , after the algorithm , but also leave the important
details about the compresssion so it can be decompressed after when , and if , needed.
*/
#include "compressor.h"


/* Recursively applies Shannon-Fano's compression algorithm to turn */
int sfcompress(float * prob , unsigned long long * new_symb , int ns){
    //We reached the final of Shannon-Fano's Algorithm
    if(ns == 1) return 1;

    float acc_prob = 0.0f;
    int n_left_tree = 0;

    for(int i=0;i < ns - 1; i++){
        acc_prob+=prob[i];
        n_left_tree ++;
        if(acc_prob >= 50.0f) break;
    }

    for(int j=0 ; j < n_left_tree ; j++) new_symb[j] = (new_symb[j] << 1);
    for(int u = n_left_tree ; u < ns ; u++) new_symb[u] = (new_symb[u] << 1) | 1ULL;

    sfcompress(prob,new_symb,n_left_tree);
    sfcompress(prob+n_left_tree,new_symb+n_left_tree,ns-n_left_tree);

    return 0;
}

int compressFile(CompressInfo * file_info){
    sortByProbability(file_info->symbols,file_info->probabilities,file_info->n_symbols);
    sfcompress(file_info->probabilities,file_info->new_symbols,file_info->n_symbols);
}