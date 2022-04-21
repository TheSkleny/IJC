// Name: htab_insert_item.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#include "htab.h"
#include "htab_structs.h"

// inserts item into hash table
// ARGS: *t - pointer to hash table
//       key - key of item to be added
bool htab_insert_item(htab_t *t, htab_key_t key){
    size_t hash = htab_hash_function(key);
    int index = (hash % t->arr_size);
    htab_item_t *item = htab_item_init(key);
    if(item == NULL){
        return false;
    }
    item->next = t->arr_ptr[index];
    t->arr_ptr[index] = item;
    t->size++;
    return true;
}