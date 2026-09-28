#include "src/includes/types.h"


/* I still need to check if this function works properly or not*/
void sortByProbability(char * symbols , float * probability , int number_s){
    for(int i=0 ; i < number_s ; i++){
        for(int j=i + 1; j < number_s ; j++)
            if(probability[j] < probability[j - 1]){
                char c_temp = symbols[j];
                float f_temp = probability[j];
                symbols[j] = symbols[j-1];
                probability[j] = probability[j - 1];

                symbols[j-1] = c_temp;
                probability[j-1] = f_temp;
            }
    }
}