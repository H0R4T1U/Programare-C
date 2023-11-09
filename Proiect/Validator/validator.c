//
// Created by horatiu on 11/7/23.
//
#include <stdio.h>
#include <string.h>
#include "validator.h"


int validator(struct transaction t){
    //The Id is guaranteed to not exist because of the way it is generated!
    // check if day, month and year are valid
    //check if sum is valid, >0
    //check if type is correct (expense or income)
    if(get_day(&t)< 1 || get_day(&t) > 31){

        printf("Invalid day!\n");
        return 0;
    }
    if(get_month(&t) < 1 || get_month(&t) > 12){
        printf("Invalid month!\n");
        return 0;
    }
    if(get_year(&t) < 2000 || get_year(&t) > 2023){
        printf("Invalid year!\n");
        return 0;
    }
    if(get_sum(&t) < 0){
        printf("Invalid amount!\n");
        return 0;
    }
    if(strcmp(get_type(&t), "income") != 0 && strcmp(get_type(&t),"expense") != 0){

        printf("Invalid type!\n");
        return 0;
    }

    return 1;

}