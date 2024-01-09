//
// Created by horatiu on 11/7/23.
//

#include <stdio.h>
#include <ctype.h>
#include "mainMenu.h"

#include <string.h>

#include "../Login/Login.h"
#include "../Views/transactionsView.h"
#include "../Repository/fileRepository.h"
#include "../Services/Reports.h"
#include "../Utility/Utility.h"


void printMainMenu(){
    printf("\033[1;36m################# MAIN MENU #################\033[1;0m\n");
    printf("1. Add Transaction\n");
    printf("2. Transactions History\n");
    printf("3. Check Account Balance\n");
    printf("4. Resolve Pending Requests\n");
    printf("R. Financial Report\n");
    printf("S. Export To CSV\n");
    printf("q. Exit\n");
    printf("x. Log-Out\n");
}
void printAddTransactionMenu() {
    printf("1. Deposit/Withdrawal Money\n");
    printf("2. Transfer/Request Money\n");
    printf("Q. Back\n");
}


void addTransactionMenu(struct account** accounts, int len_accounts, struct transaction  ** transactions,int* len_transactions,int session) {
    // read id, day, month, year, sum, type, description
    // call addTransaction
    // print success or error
    while(1) {
        printAddTransactionMenu();
        char option = tolower(getchar());
        if(option == '1') {
            intraTransactionUi(transactions,len_transactions,session);
        }else if(option == '2') {
             transferTransactionUI(accounts,len_accounts,transactions,len_transactions,session);
        }else if(option == 'q') {
            break;
        }
    }
}

void intraTransactionUi(struct transaction  ** transactions,int* len_transactions,int session) {
    int day, month, year, sum,id_account;
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

    getchar();

    printf("Enter description: ");
    fgets(description, 100, stdin);

    stringToUpper(type);
    stringToUpper(description);
    if(addTransaction(transactions,session, day, month, year, sum, type, description,*len_transactions)){
        printf("Transaction added successfully\n");
        save_transaction_csv(*transactions,*len_transactions);
        *len_transactions++;
    }else{
        printf("Transaction could not be added\n");
    }
};

void mainMenu(struct account** accounts, int len_accounts, struct transaction ** transactions,int len_transactions) {
    /* Main Menu
     * adds transactions
     * shows transactions
     * resolve pending transactions
     * create transactions report
     * export data
     * login/sign-in
     * logout
     * exit
     */
    int session = 0;
    login_menu(accounts,&len_accounts,&session);
    printMainMenu();

    while (session != 0) {
        char option = tolower(getchar());
        if(option == '1') {
            addTransactionMenu(accounts,len_accounts,transactions,&len_transactions,session);
            printMainMenu();
        }
        else if(option == '2') {
            printTransactions(*transactions,len_transactions,session);
            printMainMenu();
        }else if(option == '3'){
            int balance = checkAccoundBalance(*transactions,len_transactions,session);
            int index = get_loc_by_id(*accounts,len_accounts,session);
            struct account* accs = *accounts;
            set_balance(&accs[index],balance);
            save_account_csv(*accounts,len_accounts-1);
            printAccountBalance(*accounts,len_accounts,session,balance);
            printMainMenu();
        }else if(option == '4'){
            resolve_pending(*accounts,len_accounts,session,*transactions,len_transactions);
            printMainMenu();
        }else if(option == 'r'){
            financialReportMenu(*transactions,len_transactions,session);
            printMainMenu();
        }else if (option == 's') {
            char* file_ext;
            printf("1.CSV\n");
            printf("2.PDF\n");
            printf("3.Excel\n");
            char opt = tolower(getchar());
            while(opt != '1' && opt != '2' && opt != '3') {
                opt = tolower(getchar());
            }
            if(opt == '1') {
                file_ext = ".csv";
            }else if(opt == '2') {
                file_ext = ".pdf";
            }else {
                file_ext = ".xlsx";
            }
            export_data_csv(*accounts,len_accounts,*transactions,len_transactions,session,file_ext);
            printMainMenu();
        }else if(option == 'x') {
            session = 0;
            login_menu(accounts,&len_accounts,&session);
            printMainMenu();
        }else if(option == 'q') {
            session = 0;
            break;
        }
    }
}

void financialReportMenu(struct transaction * transactions,int len_transactions,int session) {
    // read start day, start month, start year, end day, end month, end year
    // call financialReport
    int dayL, monthL, yearL, dayR, monthR, yearR;
    printf("Enter start day: ");
    scanf("%d", &dayL);
    printf("Enter Start Month : ");
    scanf("%d", &monthL);
    printf("Enter Start Year : ");
    scanf("%d", &yearL);
    printf("Enter End Day: ");
    scanf("%d", &dayR);
    printf("Enter End Month : ");
    scanf("%d", &monthR);
    printf("Enter End Year : ");
    scanf("%d", &yearR);
    financialReport(transactions,len_transactions,session, dayL, monthL, yearL, dayR, monthR, yearR);

}
void login_menu(struct account** accounts, int* len_accounts, int* session) {
    /* Login Menu
     * manages login/sign-up systems
     */
    while((*session) == 0 ) {
        printf("\033[1;36m################# LOGIN MENU #################\033[1;0m\n");
        printf("1:Log-In\n");
        printf("2:Sign-up\n");
        printf("Q:Exit\n:");
        char option = tolower(getchar());

        if(option == '1') {
            *session = login(*accounts,*len_accounts);
        }else if(option == '2') {
            if(sign_up(accounts,*len_accounts)) {
                save_account_csv(*accounts,*len_accounts);
                *(len_accounts) = 1+ (*len_accounts);
            }
        }else if(option == 'q') {
             break;
        }
    }
}

void transferTransactionUI(struct account** accounts, int len_accounts, struct transaction  ** transactions,int *len_transactions,int session) {
    /* Transfer money between two accounts
    */
    while(1) {
        printf("1. Transfer Money\n");
        printf("2. Request Money\n");
        printf("q. Back\n:");
        char option = tolower(getchar());
        if(option == 'q') {
            break;
        }else if(option == '1' || option == '2') {
            int beneficiary_id = 0;
            int day, month, year, sum;
            char type[10];
            char description[100];
            printf("Enter The account:");
            scanf("%d",&beneficiary_id);

            printf("Enter day: ");
            scanf("%d", &day);


            printf("Enter month: ");
            scanf("%d", &month);

            printf("Enter year: ");
            scanf("%d", &year);

            printf("Enter sum: ");
            scanf("%d", &sum);

            if(option == '1') {
                strcpy(type,"EXPENSE");
                strcpy(description,"Transfer");
                addTransfer(transactions,session, day, month, year, sum, type, description,len_transactions,accounts,len_accounts);
                strcpy(type,"INCOME");
                addTransfer(transactions,beneficiary_id, day, month, year, sum, type, description,len_transactions,accounts,len_accounts);

            }else if(option == '2') {
                strcpy(type,"REQUEST");
                strcpy(description,"Money Request");
                // PRIMA DATA SE ADAUGA TRANZACTIA DE EXPENSE SI APOI CEA DE INCOME!!!!
                addTransfer(transactions,beneficiary_id, day, month, year, sum, type, description,len_transactions,accounts,len_accounts);
                strcpy(type,"PENDING");
                addTransfer(transactions,session, day, month, year, sum, type, description,len_transactions,accounts,len_accounts);

            }

        }
    }
}