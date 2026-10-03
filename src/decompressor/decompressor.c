#include "decompressor.h"
#define INVALID_PATH 1
#define NO_HEADER 2


/*Error handler for Decompression function*/
static int dc_error_handler(int flags){
    if(flags == INVALID_PATH){
        printf("[ERROR] Decompression was tried on a invalid path\n");
        return INVALID_PATH;
    }
    else if(flags == NO_HEADER){
        printf("[ERROR] The file provided by the path doesn't include a decompression header\n");
        return NO_HEADER;
    }
}

/*Parses file header to store the information on each symbol that exists and keeps its frequency to calculate
the probability to then apply the Shannon-Fano's algorithm to decompress the file*/
int readFileHeader(FILE* file,CompressInfo* f_info){

}

/*Decompresses the file back to normal given the information after the execution of Shannon-Fano's algorithm*/
static void decompress(FILE* ext_file ,CompressInfo* f_info){

}


/*Decompression function that grabs a compressed file and decompresses it back to normal */
static int decompress_handler(char * path){
    CompressInfo f_info = init_compress_info();

    FILE * compressed_file = fopen(path,"r");
    if(compressed_file == NULL) return (dc_error_handler(INVALID_PATH));

    int is_compressed_file = readFileHeader(compressed_file,&f_info);
    fclose(compressed_file);

    if(!is_compressed_file) return (dc_error_handler(NO_HEADER));
    
    compressed_file = fopen(path,"r");
    decompress(compressed_file,&f_info);
    return 0;
}