//
// Created by mepho on 11/7/23.
//


#include "transaction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_id(struct transaction *t) {
    return t->id;
}


int get_day(struct transaction* t) {
    return t->day;
}


int get_month(struct transaction* t) {
    return t->month;
}


int get_year(struct transaction *t) {
    return t->year;
}


int get_sum(struct transaction* t) {
    return t->sum;
}


char* get_type(struct transaction *t) {
    return t->type;
}


char* get_description(struct transaction* t) {
    return t->description;
}


void set_day(struct transaction* t, int day) {
    t->day = day;
}


void set_month(struct transaction* t, int month) {
    t->month = month;
}


void set_year(struct transaction* t, int year) {
    t->year = year;
}


void set_sum(struct transaction* t, int sum) {
    t->sum = sum;
}


void set_type(struct transaction* t, char* type) {
    strncpy(t->type,type,10);


}


void set_description(struct transaction* t, char* description) {
    strcpy(t->description,description);
}

struct transaction  createTransaction(int id, int day, int month, int year, int sum, char type[], char description[]){
    struct transaction t;
    t.id = id;
    set_day(&t, day);
    set_month(&t, month);
    set_year(&t, year);
    set_sum(&t, sum);
    set_type(&t, type);
    set_description(&t, description);


    return t;
}

