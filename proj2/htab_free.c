// Name: htab_free.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#include "htab.h"
#include "htab_structs.h"

// destructor of hash table
// ARGS: *t - pointer to hash table
void htab_free(htab_t * t){
    htab_clear(t);
    free(t->arr_ptr);
    free(t);
}