#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

#define INVALID_PATH 1
#define NO_PATH 2
#define NOT_COMPRESSABLE 3




int error_handler(int error , int i){
    if(error == INVALID_PATH){
        printf("[ERROR]You entered a invalid file path at argument %d\n , or the file exists ,"
            "but as a line over 2048 symbols" , i - 1);
        return INVALID_PATH;
    }
    else if(error == NO_PATH){
        printf("[ERROR]You need to enter a file path to compress.\n");
        return NO_PATH;
    }
    else if(error == NOT_COMPRESSABLE){
        printf("[ERROR]You entered at position %d of your arguments , a non compressable file.\n" , i - 1);
        return NOT_COMPRESSABLE;
    }
}


int main(int argc , char ** argv){
    if(argc < 2) return error_handler(NO_PATH,0);
    CompressInfo file_info = init_compress_info();
    for(int i=1;i<argc;i++){

        int exists_path = parseArguments(argv[i],&file_info);
        if(!exists_path) return error_handler(INVALID_PATH,i);

        int compressable = compressFile(&file_info);
        if(!compressable) return error_handler(NOT_COMPRESSABLE,i);
    }
    return 0;
}