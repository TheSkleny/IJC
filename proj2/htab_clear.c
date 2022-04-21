// Name: htab_clear.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#include "htab.h"
#include "htab_structs.h"

// deletes all records from hash table
// ARGS: *t - pointer to hash table
void htab_clear(htab_t * t){
    htab_item_t *to_free;
    htab_item_t *act;
    size_t prev_arr_size = t->arr_size;
    for(size_t i = 0; i < t->arr_size; i++){
        if(t->arr_size != prev_arr_size){
                i = 0;
                prev_arr_size = t->arr_size;
            }
        act = t->arr_ptr[i];
        while(act != NULL){
            to_free = act;
            act = act->next;
            if(htab_erase(t, to_free->pair.key) == false){
                fprintf(stderr, "ERROR: Chyba pri uvolnovani.\n");
            }
            if(t->arr_size != prev_arr_size){
                i = -1;
                break;
            }
        }
    }
    t->size = 0;
}