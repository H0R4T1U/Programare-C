#include <stdio.h>
#include <stdlib.h>
#include "./Repository/transaction.h"
#include "./Repository/fileRepository.h"
#include "./Ui/mainMenu.h"
#include "./Tests/testService.h"
#include "Login/Login.h"
#include "Utility/dynamic_allocation.h"

int main() {
    //testAll();
    int len_transactions = 1;
    int len_accounts = 1;
    struct transaction* transactions = allocateTransaction();
    struct account* accounts = allocateAccount();
    sign_up(accounts,len_accounts);
    int id = login(accounts,len_accounts);
    printf("%d",id);
    create_csv(accounts,id);
    //loadFile("FinancialData.txt", transactions);
    //mainMenu(transactions);
    free(transactions);
    free(accounts);
    return 0;
}
