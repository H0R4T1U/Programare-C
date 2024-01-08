//
// Created by h on 1/7/24.
//

#include "dynamic_allocation.h"

#include <stdio.h>
#include <stdlib.h>

struct account* allocateAccount() {
    struct account* a =  (struct account*)malloc(1*sizeof(struct account));
    return a;

}

struct transaction* allocateTransaction() {
    return (struct transaction*)malloc(sizeof(struct transaction));
}

int reallocAccount(struct account** a,int n) {
    n++;
    *a = (struct account*)realloc(*a,n*sizeof(struct account));
    if(*a == NULL) {
        fprintf(stderr,"Can't allocate more memory!");
        return 0;
    }else {

        return n;
    }

}
struct transaction* reallocTransaction(struct transaction* a, int* n) {
    (*n)++;
    struct transaction* tmp = realloc(a,(*n)*sizeof(struct transaction));
    if(tmp == NULL) {
        printf("Can't allocate more memory!");
        return 0;

    }else {
        return tmp;
    }

}
