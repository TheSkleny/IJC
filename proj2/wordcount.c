// Name: wordcount.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "io.h"
#include "htab.h"
#include "htab_structs.h"

#define MAX_WORD_LEN 127
#define HTAB_INIT_SIZE 3023 //it is prime number, in hash table is good practice to use prime number as its size because of better distribution of records across hash table

int main(void){

    //initialization of hash table
    htab_t *table = htab_init(HTAB_INIT_SIZE);
    if(table == NULL){
        fprintf(stderr, "ERROR: Chyba pri alokaci tabulky.\n");
        return 1;
    }
    char str[MAX_WORD_LEN + 1];
    FILE *f = stdin;
    int word_len;
    bool first_longer = true;

    //reading of words from file
    while((word_len = read_word(str, MAX_WORD_LEN, f)) != EOF){
        if(word_len > MAX_WORD_LEN && first_longer == true){
            fprintf(stderr, "WARNING: Slovo '%s' je delsi nez povoleny limit. Pokracuji se zkracenymi slovy.\n", str);
            first_longer = false;
        }
        htab_pair_t *pair =  htab_lookup_add(table, str);
        if(pair == NULL){
            fprintf(stderr, "ERROR: Chyba pri pridavani zaznamu.\n");
            return 1;
        }
        pair->value++;
    }

    //print of all words and number of their occurences
    for(size_t i = 0; i < table->arr_size; i++){
        htab_item_t *act = table->arr_ptr[i];
        while(act != NULL){
            printf("%s\t%i\n", act->pair.key, act->pair.value);
            act = act->next;
        }
    }

    //free of hash table and close of file
    htab_free(table);
    fclose(f);
    return 0;
}