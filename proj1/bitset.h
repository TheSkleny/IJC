// Name: bitset.h
// IJC_DU1 solution - task A
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 27.02.2022

#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include "error.h"

#ifndef BITSET_H
#define BITSET_H

// incilatization of datatypes used for operating with bit fields
typedef unsigned long BitSet_t[];
typedef unsigned long BitSet_index_t;

// Macro for initialization of array for storing bits
// ARGS: jmeno_pole - Name of bit field
//       velikost - Number of bits to be stored in array
#define BitSet_create(jmeno_pole, velikost) static_assert(velikost > 0, "Velikost pole musi byt vetsi nez 0.");\
    unsigned long jmeno_pole[((velikost / (sizeof(unsigned long) * CHAR_BIT)) + ((velikost % (sizeof(unsigned long) * CHAR_BIT)) > 0 ? 1 : 0)) + 1] = {velikost, 0};

// Macro for allocation of array for storing bits
// ARGS: jmeno_pole - Name of bit field
//       velikost - Number of bits to be stored in array
#define BitSet_alloc(jmeno_pole, velikost) assert(velikost > 0);\
    unsigned long *jmeno_pole = calloc((((velikost / (sizeof(unsigned long) * CHAR_BIT)) + ((velikost % (sizeof(unsigned long) * CHAR_BIT)) > 0 ? 1 : 0)) + 1), sizeof(unsigned long)); \
    if(jmeno_pole == NULL){\
        fprintf(stderr, "bitset_alloc: Chyba alokace pameti\n");\
        return 1;\
    }\
    *jmeno_pole = velikost;

// Frees memory allocated by Bitset_alloc
// ARGS: jmeno_pole - Name of bit field for free
#ifdef USE_INLINE
    inline void BitSet_free(BitSet_t jmeno_pole){
        free(jmeno_pole);
    }
#else
    #define BitSet_free(jmeno_pole) free(jmeno_pole)
#endif

// Returns size of bit field
// ARGS: jmeno_pole - Name of array
#ifdef USE_INLINE
    inline unsigned long BitSet_size(BitSet_t jmeno_pole){
        return jmeno_pole[0];
    }
#else
    #define BitSet_size(jmeno_pole) jmeno_pole[0]
#endif

// Sets bit on given position to given value (0/1)
// ARGS: jmeno_pole - Name of bit field
//       index - position of bit to be set
//       vyraz - value to be set on bit (0/1)
#ifdef USE_INLINE
    inline void BitSet_setbit(BitSet_t jmeno_pole, BitSet_index_t index, unsigned long vyraz){
        if(index >= BitSet_size(jmeno_pole)){
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", index, (unsigned long)(jmeno_pole[0] - 1));
        }
        else{
            if(vyraz){
                jmeno_pole[(index / (sizeof(unsigned long) * CHAR_BIT) + 1)] |= ((unsigned long)1 << (index % (sizeof(unsigned long) * CHAR_BIT)));
            }
            else{
                jmeno_pole[(index / (sizeof(unsigned long) * CHAR_BIT) + 1)] &= ~((unsigned long)1 << (index % (sizeof(unsigned long) * CHAR_BIT)));
            }
        }
    }
#else
    #define BitSet_setbit(jmeno_pole, index, vyraz) \
        do{ \
            if((unsigned long)index >= BitSet_size(jmeno_pole)){ \
                error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)(jmeno_pole[0] - 1)); \
            } \
            else{ \
                if(vyraz){ \
                    jmeno_pole[(index / (sizeof(unsigned long) * CHAR_BIT) + 1)] |= ((unsigned long)1 << (index % (sizeof(unsigned long) * CHAR_BIT))); \
                } \
                else{ \
                    jmeno_pole[(index / (sizeof(unsigned long) * CHAR_BIT) + 1)] &= ~((unsigned long)1 << (index % (sizeof(unsigned long) * CHAR_BIT))); \
                } \
            } \
        } \
        while(0)
#endif

// Gets the value of bit on given position
// ARGS: jmeno_pole - Name of bit field
//       index - position of bit to get value from  
#ifdef USE_INLINE
    inline unsigned long BitSet_getbit(BitSet_t jmeno_pole, BitSet_index_t index){
        if(index >= BitSet_size(jmeno_pole)){
            error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", index, (unsigned long)(jmeno_pole[0] - 1));
            return 1;
        }
        else{
            return jmeno_pole[(index / (sizeof(unsigned long) * CHAR_BIT) + 1)] & ((unsigned long) 1 << (index % (sizeof(unsigned long) * CHAR_BIT)));
        }
    }
#else
    #define BitSet_getbit(jmeno_pole, index) \
        ((unsigned long)index >= BitSet_size(jmeno_pole)) ? \
        (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)(jmeno_pole[0] - 1)), (unsigned long)0) : \
        (jmeno_pole[(index / (sizeof(unsigned long) * CHAR_BIT) + 1)] & ((unsigned long) 1 << (index % (sizeof(unsigned long) * CHAR_BIT))))
#endif

#endif // BITSET_H