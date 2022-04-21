// Name: eratosthenes.c
// IJC_DU1 solution - task A
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 27.02.2022

#include <stdio.h>
#include <limits.h>
#include "bitset.h"
#include <math.h>
#include "eratosthenes.h"

// Eratosthenes function - finds all prime numbers in given bit field
// sets non-prime numbers in bit field to 1, prime numbers to 0
void eratosthenes(BitSet_t pole){
    BitSet_setbit(pole, 0, 1);
    BitSet_setbit(pole, 1, 1);
    for(BitSet_index_t i = 2; i < sqrt(BitSet_size(pole)); i++){
        if(BitSet_getbit(pole, i) == 0){
            for(unsigned long n = 2; n*i < BitSet_size(pole); n++){
                BitSet_setbit(pole, n*i, 1);
            }
        }
    }
    
}
