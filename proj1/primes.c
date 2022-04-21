// Name: primes.c
// IJC_DU1 solution - task A
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 27.02.2022



#include <stdio.h>
#include "bitset.h"
#include "eratosthenes.h"
#include <time.h>

// Main function for finding and printing TOP 10 prime numbers from interval 0-300 000 000
int main(void)
{
    // Start of time measuring to know how much time finding prime numbers take 
    clock_t start;
    start = clock();

    // Create of bit field - BitSet_create or BitSet_alloc
    //BitSet_alloc(pole, 300000000);
    BitSet_create(pole, 300000000);

    // Eratosthenes algorithm to find prime numbers
    eratosthenes(pole);
    
    // Temporary array and counter to store TOP 10 prime numbers
    int pocet = 0;
    int top_primes[10];

    for(int i = BitSet_size(pole) - 1; i >= 0 ; i--){ 
        if(BitSet_getbit(pole, i) == 0){
            top_primes[pocet] = i;
            pocet++;
        }
        if(pocet == 10){
            break;
        }
    }

    // Loop to print TOP 10 prime numbers
    for(int i = 9; i >=0; i--){
        printf("%d\n", top_primes[i]);
    }

    // Free of bit field if BitSet_alloc is used
    //BitSet_free(pole);

    // Print of the amount of time needed for finding prime numbers
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    
    return 0;
}
