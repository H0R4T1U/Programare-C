//
// Created by horatiu on 11/7/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "mainMenu.h"


void printMainMenu(){
    printf("1. Add transaction\n");
    printf("2. Print transactions\n");
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

    if(addTransaction(transactions, day, month, year, sum, type, description)){
        printf("Transaction added successfully\n");
    }else{
        printf("Transaction could not be added\n");
    }
}

void printTransactions(struct transaction transactions[]) {
    // print all transactions
    int len = lengthTransactions(transactions);
    for(int i = 0; i < len; i++) {
        struct transaction t = transactions[i];
        printf("ID:%d\n", get_id(&t));
        printf("Data: %d %d %d\n", get_day(&t), get_month(&t),get_year(&t));
        printf("Amount: %d\n", get_sum(&t));
        printf("Type: %s\n", get_type(&t));
        printf("Descriere: %s\n", get_description(&t));
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
        }else if (option == 'q') {
            break;
        }
        option = getchar();
    }
}

