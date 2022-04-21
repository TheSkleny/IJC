// Name: htab_erase.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#include "htab.h"
#include "htab_structs.h"

// deletes record from hash table
// ARGS: *t - pointer to hash table
//       key - key of record to be deleted
bool htab_erase(htab_t * t, htab_key_t key){
    size_t hash = htab_hash_function(key);   
    int index = (hash % t->arr_size);

    htab_item_t *prev = NULL;
    htab_item_t *act = t->arr_ptr[index];
    while(act != NULL && strcmp(act->pair.key, key)){
        prev = act;
        act = act->next;
    }
    if(act == NULL){
        return false;
    }
    if(prev == NULL){
        t->arr_ptr[index] = act->next;
    }
    else{
        prev->next = act->next;
    }
    free((char *)act->pair.key);
    free(act);
    t->size--;
    if(((t->size / t->arr_size) < AVG_LEN_MIN) && t->arr_size > 1){
        htab_resize(t, t->arr_size/2);
    }
    return true;
}