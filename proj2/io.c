// Name: io.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#include "io.h"

// reads file word by word
// ARGS: *s - string, here is stored word from file
//       max - maximal length of word
//       *f - file
int read_word(char *s, int max, FILE *f){
    int character;
    int iterator = 0;
    int to_ret = EOF;

    //skip all whitespaces
    while ((character = getc(f)) != EOF && isspace(character));
    s[iterator++] = character;
    
    
    while((character = getc(f)) != EOF){
        if(isspace(character)){
            break;
        }
        s[iterator] = character;
        //word is too long
        if(iterator == max){
            s[iterator] = '\0';
            while((!isspace(character = getc(f)) && character != EOF));
            iterator++;
            break;
        }
        iterator++;
    }
    s[iterator] = '\0';
    if(character != EOF){
        to_ret = iterator;
    }
    return to_ret;
}