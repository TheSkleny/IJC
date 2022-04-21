// Name: htab_resize.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#include "htab.h"
#include "htab_structs.h"

// changes size of array in hash_table, rehashes all records to right positions
// ARGS: *t - pointer to hash table
//       newn - new size of hash table
void htab_resize(htab_t *t, size_t newn){
    if(newn < 1){
        fprintf(stderr, "ERROR: prilis male n pro realokaci\n");
    }
    else{
        //backup of all pairs
        size_t prev_size = t->size;
        htab_pair_t bcup_pairs[prev_size];
        int iterator = 0;
        for(size_t i = 0; i < t->arr_size; i++){
            htab_item_t *act = t->arr_ptr[i];
            while(act != NULL){
                char *tmp = malloc(sizeof(char) * (strlen(act->pair.key) + 1));
                bcup_pairs[iterator].value = act->pair.value;
                strcpy(tmp, act->pair.key);
                bcup_pairs[iterator].key = tmp;
                act = act->next;
                iterator++;
            }
        }

        //clear of table
        htab_item_t *item;
        htab_item_t *toFree;
        for(size_t i = 0; i < t->arr_size; i++){
            item = t->arr_ptr[i];
            while(item != NULL){
                toFree = item;
                item = item->next;
                free((char *)toFree->pair.key);
                free(toFree);
            }
            t->arr_ptr[i] = NULL;
        }

        //realloc of arr_ptr
        htab_item_t **tmp;
        tmp = realloc(t->arr_ptr, sizeof(htab_item_t *) * newn);
        if(tmp != NULL){
            t->arr_ptr = tmp;
            t->arr_size = newn;
        }
        t->size = 0;

        //initialization of all pointers in array to NULL
        for(size_t i = 0; i < t->arr_size; i++){
            t->arr_ptr[i] = NULL;
        }

        //insert all items back to right locations
        for(size_t i = 0; i < prev_size; i++){
            htab_insert_item(t, bcup_pairs[i].key);
            htab_find(t, bcup_pairs[i].key)->value = bcup_pairs[i].value;
        }

        for(size_t i = 0; i < prev_size; i++){
            free((char *)bcup_pairs[i].key);
        }
    }
}