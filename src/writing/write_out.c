#include "write_out.h"



void writeDecompressionInfo(FILE * new_file , CompressInfo * file_info){

}

static void write_out_compressed(BitWriter* bw , unsigned long long value , int n_bits){
    for(int i=n_bits - 1;i>=0;i--){ //Reads MSB first , left to right
        bw->buffer = (bw->buffer << 1) | ((value >> i) & 1ULL);
        bw->flush_bits++;
        if(bw->flush_bits == 8){
            fputc(bw->buffer,bw->file);
            bw->flush_bits = 0;
            bw->buffer = 0;
        }
    }
}

static void flushout(BitWriter * bw){
    if(bw->flush_bits > 0){
        bw->buffer <<= (8 - bw->flush_bits); 
        fputc(bw->buffer,bw->file);
        bw->flush_bits = 0;
        bw->buffer = 0;
    }
}

int count_bits(unsigned long long value){
    int counter=0;
    while((value>>counter)!=0) counter++;
    return counter;
}


void writeCompressedFileLine(char * line , CompressInfo * file_info , FILE * new_file , BitWriter * bw){
    if(file_info->n_symbols == 0){
        printf("[ATTENTION] No symbols found in file\n");
        return;
    }

    int i=0;
    while(line[i]!='\0'){
        int j=0;
        for(;j<file_info->n_symbols && line[i] != file_info->symbols[j];j++);
        if(j == file_info->n_symbols) printf("[ERROR] Error while finding symbol\n");

        unsigned long long temp = file_info->new_symbols[j];
        if(temp == 0){fprintf(new_file,"%c",'\0'); file_info->number_zeros++;}
        else write_out_compressed(bw,temp,file_info->code_len[j]);
        i++;
    }
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

    //This refers to the file that is being compressed
    fclose(file_info->file);//Assumes file exists
    file_info->file = fopen(file_info->file_path,"r"); //Opens it again to read the file one more time to print

    BitWriter bw;
    bw.file = new_file;
    bw.buffer = 0;
    bw.flush_bits = 0;

    char line[LINE_MAX];
    while(fgets(line,LINE_MAX,file_info->file)){
        writeCompressedFileLine(line,file_info,new_file,&bw);
    }
    flushout(&bw);

    writeDecompressionInfo(new_file,file_info);

    fclose(file_info->file);
    fclose(new_file);
}