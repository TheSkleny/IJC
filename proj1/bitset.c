// Name: bitset.c
// IJC_DU1 solution - task A
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 27.02.2022

#include "bitset.h"

#ifdef USE_INLINE

//declaration of inline function
extern inline unsigned long BitSet_size(BitSet_t jmeno_pole);
extern inline void BitSet_setbit(BitSet_t jmeno_pole, BitSet_index_t index, unsigned long vyraz);
extern inline unsigned long BitSet_getbit(BitSet_t jmeno_pole, BitSet_index_t index);
extern inline void BitSet_free(BitSet_t jmeno_pole);

#endif