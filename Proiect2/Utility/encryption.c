//
// Created by h on 1/7/24.
//

#include "encryption.h"

#include <string.h>

void encrypt(char* word, int key) {
    for (int n = 0, len = strlen(word); n < len; n++) {
        char currentLetter = word[n];

        // Check if the letter is lowercase
        if (currentLetter >= 'a' && currentLetter <= 'z') {
            word[n] = ((currentLetter - 'a' + key) % 26) + 'a';
        }
        // Check if the letter is uppercase
        else if (currentLetter >= 'A' && currentLetter <= 'Z') {
            word[n] = ((currentLetter - 'A' + key) % 26) + 'A';
        }
    }
}

void decrypt(char* word,int key) {

    // all the letters in the first argument
    for (int n = 0, len = strlen(word); n < len; n++)
    {
        int currentLetter = word[n];

        char cipher = currentLetter + key;

        // make sure the next letter isn't over 26 or it isn't a ascii letter
        // if it is, do %26
        if ((currentLetter - 'a') + key > 26)
        {
            key = (currentLetter - 'a' + key) % 26;
            cipher = 'a' + key;
        }
        word[n] = cipher;
        // reset the key and do the next letter
    }
}