//
// Created by mepho on 11/10/23.
//

#ifndef PROIECT_FILEREPOSITORY_H
#define PROIECT_FILEREPOSITORY_H
#include "./transaction.h"

void loadfile(char* filename, struct transaction * transactions);
void savefile(char* filename, struct transaction * transactions, int length);
#endif //PROIECT_FILEREPOSITORY_H
