#include "write_out.h"



void writeDecompressionInfo(FILE * new_file , CompressInfo * file_info){

}



void writeCompressedFileLine(char * line , CompressInfo * file_info , FILE * new_file){
    if(file_info->n_symbols == 0){
        printf("[ATTENTION] No symbols found in file\n");
        return;
    }

    int i=0;
    while(line[i]!='\0'){
        int j=0;
        for(;j<file_info->n_symbols && line[i] != file_info->symbols[j];j++);

        unsigned long long temp = file_info->new_symbols[j];
        while(temp!=0){
            unsigned long long three_r_bits = (temp & 1ULL) 
                                            | (temp & (1ULL<<1)) 
                                            | (temp & (1ULL << 2));
            char flush = (char)three_r_bits;
            fprintf(new_file,"%c",flush);
            if(IS_DEBUGGING_WRITEOUT)
                printf("Just printed : %c for symbol %c\n",flush,file_info->symbols[j]);
            temp = temp >> 3;
        }
        i++;
    }
    fprintf(new_file,"\n");
}


void writeOutCompressedFile(CompressInfo * file_info){
    int length = strlent(file_info->file_path);
    char new_path[length + 5];
    append_zip(file_info->file_path,new_path);
    FILE * new_file = fopen(new_path,"r");
    if(new_file!=NULL){
        fclose(new_file);
        printf("Já possui um ficheiro com o nome %s , pelo que o programa não vai dar overwrite\n",
            new_path);
        return;
    }
    new_file = fopen(new_path,"w");

    fclose(file_info->file);//Assumes file exists
    fopen(file_info->file_path,"r"); //Opens it again to read the file one more time to print

    char line[LINE_MAX];
    while(fgets(line,LINE_MAX,file_info->file)){
        writeCompressedFileLine(line,file_info,new_file);
    }

    writeDecompressionInfo(new_file,file_info);
}