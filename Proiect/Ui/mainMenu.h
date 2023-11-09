//
// Created by horatiu on 11/7/23.
//

#ifndef PROIECT_MAINMENU_H
#define PROIECT_MAINMENU_H
#include "../Repository/transaction.h"
#include "../Services/crud.h"


void mainMenu(struct transaction  * transactions);
void addTransactionMenu(struct transaction * transactions);
void stringToUpper(char* str);
void printMainMenu();

#endif //PROIECT_MAINMENU_H
