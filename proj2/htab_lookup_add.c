// Name: htab_lookup_add.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022


#include "htab.h"
#include "htab_structs.h"

// finds record in hash table, if record doesn't exist, creates it
// ARGS: *t - pointer to hash table
//       key - key of item
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key){
    htab_pair_t *to_ret = htab_find(t, key);
    if(to_ret == NULL){
        if(!htab_insert_item(t, key)){
            return NULL;
        }
    }
    if(((t->size / t->arr_size) > AVG_LEN_MAX)){
        htab_resize(t, t->arr_size * 2);
    }
    to_ret = htab_find(t, key);
    return to_ret;
}