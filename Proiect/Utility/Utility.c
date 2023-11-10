//
// Created by mepho on 11/10/23.
//

#include "Utility.h"


void stringToUpper(char* str){
    for(int i = 0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }
}