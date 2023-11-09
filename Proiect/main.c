#include <stdio.h>
#include "./Repository/transaction.h"
#include "./Repository/fileRepository.h"
#include "./Ui/mainMenu.h"

int main() {

    struct transaction transactions[100];
    for(int i= 0 ; i < 100; i++){
        struct transaction a = {0,25,0,0,0,"",""};
        transactions[i] = a  ;
    }
    loadfile("FinancialData.txt", transactions);
    mainMenu(transactions);

    return 0;
}
