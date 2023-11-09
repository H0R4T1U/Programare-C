//
// Created by horatiu on 11/7/23.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "mainMenu.h"
#include "../Views/transactionsView.h"
void stringToUpper(char* str);

void printMainMenu(){
    printf("1. Add Transaction\n");
    printf("2. Transactions History\n");
    printf("3. Check Account Balance\n");
    printf("S. Save to FILE\n");
    printf("q. Exit\n");
}


void addTransactionMenu(struct transaction * transactions) {
    // read id, day, month, year, sum, type, description
    // call addTransaction
    // print success or error

    int day, month, year, sum;
    char type[10];
    char description[100];
    printf("Enter day: ");
    scanf("%d", &day);


    printf("Enter month: ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    printf("Enter sum: ");
    scanf("%d", &sum);

    printf("Enter type: ");
    scanf("%s" , type);

    printf("Enter description: ");
    fgets(description, 100, stdin);

    stringToUpper(type);
    stringToUpper(description);
    if(addTransaction(transactions, day, month, year, sum, type, description)){
        printf("Transaction added successfully\n");
    }else{
        printf("Transaction could not be added\n");
    }
}


void mainMenu(struct transaction * transactions) {
        // menu for adding transactions
        //  print transactions
        //  exit
    printMainMenu();
    int option = getchar();
    while (1) {

        if(option == '1') {
            addTransactionMenu(transactions);
            printMainMenu();
        }
        else if(option == '2') {
            printTransactions(transactions);
            printMainMenu();
        }else if(option == '3'){
            int balance = checkAccoundBalance(transactions);
            printAccountBalance(balance);
            printMainMenu();
        }else if (option == 'q') {
            break;
        }
        option = getchar();
    }
}


void stringToUpper(char* str){
    for(int i = 0; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }
}
