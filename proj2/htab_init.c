// Name: htab_init.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#include "htab.h"
#include "htab_structs.h"

// initializes hash table, returns pointer to table
// ARGS: n - size of hash table
htab_t *htab_init(size_t n){
    if(n < 1){
        fprintf(stderr, "ERROR: prilis male n pro vytvoreni tabulky\n");
        return NULL;
    }
    else{
        htab_t *ptr = malloc(sizeof(htab_t));
        if (ptr == NULL){
            return NULL;
        }
        ptr->arr_size = n;
        ptr->size = 0;
        ptr->arr_ptr = malloc(sizeof(htab_item_t *) * n);
        if (ptr->arr_ptr == NULL){
            return NULL;
        }
        for(size_t i = 0; i < n; i++){
            ptr->arr_ptr[i] = NULL;
        }

        return ptr;
    }
}