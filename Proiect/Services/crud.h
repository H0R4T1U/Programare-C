//
// Created by horatiu on 11/7/23.
//

#ifndef PROIECT_CRUD_H
#define PROIECT_CRUD_H
#include "../Repository/transaction.h"
int addTransaction(struct transaction * transactions, int day, int month, int year, int sum, char* type, char* description);
int lengthTransactions(struct transaction * transactions);
#endif //PROIECT_CRUD_H
