//
// Created by horatiu on 11/7/23.
//
#include <stdio.h>
#include "crud.h"
#include "../Validator/validator.h"

int addTransaction(struct transaction * transactions, int day, int month, int year, int sum, char * type, char * description) {
    int len = lengthTransactions(transactions);
    int id = len+1;

    struct transaction t = createTransaction(id, day, month, year, sum, type, description);

    if(validator(t)){
        transactions[len] = t;
        return 1;
    }else{
        return 0;
    }
}

int lengthTransactions(struct transaction * transactions){
    int i = 0;
    while(transactions[i].id != 0){
        i++;
    }
    return i;
}