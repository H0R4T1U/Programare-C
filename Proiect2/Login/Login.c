//
// Created by h on 1/7/24.
//

#include "Login.h"

#include <stdio.h>
#include <string.h>


int check_name(char* nume,struct account* accounts,int len_accounts);
int check_login(char* nume,char* passwd,struct account* accounts,int len_accounts);

int login(struct account* accounts,int len_accounts) {
    char nume[20];
    char passwd[15];
    printf("username:");
    scanf("%20s",nume);
    printf("Password:");
    scanf("%15s",passwd);
    int id = 0;
    id = check_login(nume,passwd,accounts,len_accounts);
    while(!id) {
        printf("\033[1;31mIncorect username/password Combination!\n");
        printf("\033[1;0musername:");
        scanf("%20s",nume);
        printf("Password:");
        scanf("%15s",passwd);
        id = check_login(nume,passwd,accounts,len_accounts);
    }
    return id;
}

void sign_up(struct account* accounts, int len_accounts) {
    char nume[20];
    char passwd[15];
    char type[10];

    printf("username:");
    scanf("%20s",nume);
    if(check_name(nume,accounts,len_accounts)) {
        fprintf(stderr,"Account Already Exist!\n");
        return;
    }
    printf("Password:");
    scanf("%15s",passwd);

    printf("Account type(credit,debit):");
    scanf("%10s",type);


    accounts[len_accounts-1] = createAccount(len_accounts,0,type,nume,passwd);
}

int check_name(char* nume,struct account* accounts,int len_accounts) {
    for(int i = 0; i < len_accounts-1; i++) {
        if( strcasecmp( get_name(&accounts[i]),nume ) == 0) {
            return 1;
        }
    }
    return 0;
}

int check_login(char* nume,char* passwd,struct account* accounts,int len_accounts) {
    for(int i = 0; i < len_accounts-1; i++) {
        if( strcmp( get_name(&accounts[i]),nume ) == 0) {
            if(strcmp(get_password(&accounts[i]),passwd) == 0) {
                return get_id_account(&accounts[i]);
            }else {
                return 0;
            }
        }
    }
    return 0;
}