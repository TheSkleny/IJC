// Name: steg-decode.c
// IJC_DU1 solution - task b
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 12.03.2022


#include "ppm.h"
#include "bitset.h"
#include "eratosthenes.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main(int argc, char const *argv[]){

    // Test, if filename is given as argument from console
    if(argc != 2){
        error_exit("Spatny pocet argumentu.\n");
    }

    struct ppm *p = ppm_read(argv[1]);
    
    unsigned size = 3 * p->xsize * p->ysize;

    BitSet_alloc(bit_pole, size);
    eratosthenes(bit_pole);


    // Alloc of first char of string to store secret message
    char* message = (char *)calloc(1, sizeof(char));
    if(message == NULL){
        BitSet_free(bit_pole);
        ppm_free(p);
        error_exit("Nepovedlo se alokovat retezec.\n");
    }


    int index = 0, shift = 0;
    bool success = false;

    // Loop through all ppm picture data on prime indexes
    for(unsigned i = 29; i < size; i++){
        if(BitSet_getbit(bit_pole, i) == 0){
            
            // Store LSB of byte from ppm data to index 0-7 in message based on value of shift
            message[index] |= ((p->data[i] & ((uint8_t)0x01)) << shift);
            shift++;

            // Separation of bits to bytes (chars)
            if(shift == 8){
                if(message[index] == '\0'){
                    success = true;
                    break;
                }
                shift = 0;
                index++;

                // Reallocation of memory by 1 char, to store another piece of message, setting this new memory to 0
                message = realloc(message, ((index + 1) * sizeof(char)));
                message[index] = 0;
            }
        }
    }

    // Print of secret mesage, if '\0' is located
    if(success == true){
        printf("%s", message);
        printf("\n");
    }
    else{
        free(message);
        BitSet_free(bit_pole);
        ppm_free(p);
        error_exit("Nepodarilo se nalezt konec zpravy.\n");
    }

    free(message);
    BitSet_free(bit_pole);

    ppm_free(p);

    return 0;
}