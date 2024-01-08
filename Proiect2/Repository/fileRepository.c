//
// Created by horatiu on 11/10/23.
//

#include "./fileRepository.h"
#include "../Validator/validator.h"
#include "../Utility/Utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "accounts.h"
#include "../Utility/dynamic_allocation.h"

void loadFile(char* filename, struct transaction * transactions){
    /*
     * This function loads the data from the file into the transactions array
     * Input: filename - the name of the file
     *       transactions - the array of transactions
     */
    FILE * fptr = NULL;
    int i = 0;
    char type[10];
    char* c;
    char description[100];
    int id = 0, day = 0,month=0,year = 0,sum = 0;
    fptr = fopen("../Repository/FinancialData.txt", "r");
    while(fscanf(fptr,"%d",&id) == 1){
        fscanf(fptr,"%d",&day);
        fscanf(fptr,"%d",&month);
        fscanf(fptr,"%d",&year);
        fscanf(fptr,"%d",&sum);
        fscanf(fptr,"%s ",type);
        fgets(description,100,fptr);

        stringToUpper(type);
        stringToUpper(description);
        struct transaction t = createTransaction(id,1, day, month, year, sum, type, description);
        if(validator(t)){
            transactions[i] = t;
            i++;
        }
    }
    fclose(fptr);

}


void saveFile(int len, struct transaction * transactions){
    /*
     * This function saves the data from the transactions array into the file
     * Input: len - the length of the transactions array
     *      transactions - the array of transactions
     */
    FILE * fptr;
    fptr = fopen("../Repository/FinancialData.txt", "w");
    for(int i = 0; i < len; i++){

        fprintf(fptr,"%d ",get_id(&transactions[i]));
        fprintf(fptr,"%d ",get_day(&transactions[i]));
        fprintf(fptr,"%d ",get_month(&transactions[i]));
        fprintf(fptr,"%d ",get_year(&transactions[i]));
        fprintf(fptr,"%d ",get_sum(&transactions[i]));
        fprintf(fptr,"%s ",get_type(&transactions[i]));
        fprintf(fptr,"%s\n",get_description(&transactions[i]));
    }
    fclose(fptr);
}



void createCSV(struct account * a,int len)
{
    // file pointer
    FILE* fptr = NULL;

    // opens an existing csv file or creates a new file.
    fptr = fopen("../Data/Accounts.csv", "w");
    fprintf(fptr,"Id,Balance,Type,Name,Password\n");
    for(int i = 0; i < len; i++) {
        fprintf(fptr,"%d,",get_id_account(&a[i]));
        fprintf(fptr,"%d,",get_balance(&a[i]));
        fprintf(fptr,"%s,",get_type_account(&a[i]));
        fprintf(fptr,"%s,",get_name(&a[i]));
        fprintf(fptr,"%s",get_password(&a[i]));
        fprintf(fptr,"\n");
    }


    fclose(fptr);
}

int loadCSV(struct account** a) {
    FILE* fptr = NULL;
    char line[1000];
    int len = 1;
    fptr = fopen("../Data/Accounts.csv","r");
    if(fptr == NULL) {
        fprintf(stderr,"FIle I/O Error");
    }
    fgets(line, 1000, fptr);
    while (feof(fptr) != 1)
    {
        char type[10],name[20],passwd[15];

        fgets(line, 1000, fptr);

        char* token = strtok(line, ",");
        int id = atoi(token);
        token = strtok(NULL, ",");
        int amount = atoi(token);
        token = strtok(NULL, ",");
        strcpy(type,token);
        token = strtok(NULL, ",");
        strcpy(name,token);
        token = strtok(NULL, "\n");
        strcpy(passwd,token);
        printf("%d,%d,%s,%s,%s\n",id,amount,type,name,passwd);
        struct account account = createAccount(id,amount,type,name,passwd);
        (*a)[len-1] = account;
        len = reallocAccount(a,len);

    }
    return len;
}
