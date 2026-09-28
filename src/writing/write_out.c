#include "write_out.h"


void writeOutCompressedFile(CompressInfo * file_info){
    int length = strlent(file_info->file_path);
    char new_path[length + 5];
    append_zip(file_info->file_path,new_path);
    
    char line[LINE_MAX];
    while(fgets(line,LINE_MAX,file_info->file)){
        
    }
}