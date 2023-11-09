//
// Created by mepho on 11/10/23.
//

#include "fileRepository.h"
#include "../Validator/validator.h"
#include "../Ui/mainMenu.h"
#include <stdio.h>

void loadfile(char* filename, struct transaction * transactions){
    FILE * fptr;
    int i = 0;
    char type[10];
    char description[100];
    int id = 0, day = 0,month=0,year = 0,sum = 0;
    fptr = fopen("./Repository/FinancialData.txt", "r");
    while(fscanf(fptr,"%d",&id) == 1){
        fscanf(fptr,"%d",&day);
        fscanf(fptr,"%d",&month);
        fscanf(fptr,"%d",&year);
        fscanf(fptr,"%d",&sum);
        fscanf(fptr,"%s",type);
        fgets(description,100,fptr);

        stringToUpper(type);
        stringToUpper(description);
        struct transaction t = createTransaction(id, day, month, year, sum, type, description);
        if(validator(t)){
            transactions[i] = t;
            i++;
        }
    }
    fclose(fptr);

}