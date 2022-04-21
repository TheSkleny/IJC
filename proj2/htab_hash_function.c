// Name: htab_hash_function.c
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "htab.h"
#include "htab_structs.h"

// hash function for hashing values into hash table
// ARGS: *str - string (key) to be hashed
size_t htab_hash_function(const char *str){
    uint32_t h = 0; // musí mít 32 bitů
    const unsigned char *p;
    for (p = (const unsigned char *)str; *p != '\0'; p++)
        h = 65599 * h + *p;
    return h;
}