//
// Created by mepho on 11/10/23.
//

#include "Reports.h"
#include "crud.h"
#include "../Views/transactionsView.h"

void financialReport(struct transaction * transactions,int dayL,int monthL,int yearL,int dayR,int monthR,int yearR){
    int n = lengthTransactions(transactions);
    struct transaction  new_transactions[100];
    int j = 0;
    for(int i = 0; i < n; i++){

        struct transaction t = transactions[i];
        int day = get_day(&t);
        int month = get_month(&t);
        int year = get_year(&t);
        int cond1 = (yearL < year && year < yearR);
        int cond2 = ( yearL == yearR && yearL == year && monthL < month && month < monthR );
        int cond3 = (yearL == yearR && monthL == monthR && year == yearL && month == monthL && dayL <= day && day <= dayR);
        int cond4 = (yearL == year && year != yearR && monthL < month || year == yearR && year != yearL && month < monthR);
        int cond5 = (yearL == year && monthL == month && year != yearR && day >= dayL || year == yearR && monthR == month && year != yearL && day <= dayR);
        if(cond1 || cond2 || cond3 || cond4 || cond5){
            new_transactions[j] = transactions[i];
            j++;
        }

    }
    printTransactions(new_transactions);
    int sum = checkAccoundBalance(new_transactions);
    printAccountBalance(sum);

}
