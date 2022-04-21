// Name: htab_for_each.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022


#include "htab.h"
#include "htab_structs.h"

// for every record in hash table call function
// ARGS: *t - pointer to hash table
//       (*f)(htab_pair_t *data) - pointer to function
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    htab_pair_t *bcup_pair = malloc(sizeof(htab_pair_t));
    bool is_safe = true;

    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t *act = t->arr_ptr[i];
        while(act != NULL){
            bcup_pair->key = act->pair.key;

            (f)(&act->pair);
            if (bcup_pair->key != act->pair.key){
                is_safe = false;
                act->pair.key = bcup_pair->key;
                break;
            }
            act = act->next;
        }
        if(is_safe == false){
            break;
        }
    }
    free(bcup_pair);
}