// Name: htab_item_init.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022


#include "htab.h"
#include "htab_structs.h"

// initializes item
// ARGS: key - key of item for inicialization
htab_item_t *htab_item_init(htab_key_t key){
    htab_item_t *ptr = malloc(sizeof(htab_item_t));
    if (ptr == NULL){
        return NULL;
    }
    ptr->next = NULL;
    char *tmp = malloc(sizeof(char) * (strlen(key) + 1));
    if(tmp == NULL){
        return NULL;
    }
    strcpy(tmp, key);
    ptr->pair.key = tmp;
    ptr->pair.value = 0;
    return ptr;
}