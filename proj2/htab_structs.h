// Name: htab_structs.h
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#ifndef __HTAB_STRUCTS_H__
#define __HTAB_STRUCTS_H__

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "htab.h"

//struct of item in hash table
struct htab_item{
    htab_pair_t pair;
    htab_item_t *next;
};

//struct of hash table
struct htab{
    size_t size;
    size_t arr_size;
    htab_item_t **arr_ptr;
};

//initializes item
htab_item_t *htab_item_init(htab_key_t key);

//inserts item to hash_table
bool htab_insert_item(htab_t *t, htab_key_t key);

#endif //__HTAB_STRUCTS_H__
