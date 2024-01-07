//
// Created by h on 1/7/24.
//

#include "dynamic_allocation.h"

#include <stdio.h>
#include <stdlib.h>

struct account* allocateAccount() {
    struct account* a =  (struct account*)malloc(sizeof(struct account));
    return a;

}

struct transaction* allocateTransaction() {
    return (struct transaction*)malloc(sizeof(struct transaction));
}

struct account* reallocAccount(struct account* a,int* n) {
    (*n)++;
    struct account* tmp = realloc(a,(*n)*sizeof(struct account));
    if(tmp == NULL) {
        printf("Can't allocate more memory!");
        return NULL;

    }else {
        return tmp;
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
