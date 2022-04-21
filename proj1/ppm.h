// Name: ppm.h
// IJC_DU1 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 12.03.2022

#include<stdlib.h>


#ifndef PPM_H
#define PPM_H

#define MAX_SIZE 8000*8000*3 // Max size of ppm picture

// Struct to store ppm data
struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);

void ppm_free(struct ppm *p);


#endif //PPM_H