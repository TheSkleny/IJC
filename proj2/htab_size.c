// Name: htab_size.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#include "htab.h"
#include "htab_structs.h"

// returns number of records in array
// ARGS: *t - pointer to hash table
size_t htab_size(const htab_t * t){
    return t->size;
}