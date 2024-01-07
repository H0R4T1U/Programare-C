//
// Created by h on 1/7/24.
//

#ifndef LOGIN_H
#define LOGIN_H

#include "../Repository/accounts.h"
#include "../Utility/dynamic_allocation.h"

    int login(struct account* accounts,int len_accounts);
    void sign_up(struct account* accounts, int len_accounts);
#endif //LOGIN_H
