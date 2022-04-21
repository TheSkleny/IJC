// Name: htab_find.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022


#include "htab.h"
#include "htab_structs.h"

// returns pointer to record from hash table, if record dosn't exist, returns NULL
// ARGS: *t - pointer to hash table
//       key - key of record to be found
htab_pair_t * htab_find(htab_t * t, htab_key_t key){
    htab_pair_t *to_ret = NULL;
    size_t hash = htab_hash_function(key);
    int index = (hash % t->arr_size);
    htab_item_t *act = t->arr_ptr[index];
    while(act != NULL){
        if(!strcmp(key, act->pair.key)){
            to_ret = &act->pair;
            break;
        }
        act = act->next;
    }
    return to_ret;
}