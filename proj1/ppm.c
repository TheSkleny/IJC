// Name: ppm.c
// IJC_DU1 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 12.03.2022

#include "ppm.h"
#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include <string.h>
#include <stdarg.h>

// returns pointer to struct ppm, which contains data from ppm picture
// ARGS: filename - name of file to be read from
struct ppm * ppm_read(const char * filename){
    struct ppm *p;

    unsigned xsize, ysize, color;

    FILE * fp;

    fp = fopen(filename, "rb");
    if(fp == NULL){
        warning_msg("Soubor %s nelze otevrit.\n", filename);
        exit(1);
    }
    
    // Test of file format
    char buffer[5];
    memset(buffer, 0, sizeof(buffer));
    for(int i = 4; i > 0; i--){
        buffer[4 - i] = filename[strlen(filename) - i];
    }
    if(strcmp(buffer, ".ppm")){
        warning_msg("Spatny format souboru.\n");
        fclose(fp);
        return NULL;
    }
    memset(buffer, 0, sizeof(buffer));


    // Test of data format
    fgets(buffer, 3, fp);
    if(strcmp(buffer, "P6")){
        warning_msg("Spatny format souboru PPM, ocekaval se P6.\n");
        fclose(fp); 
        return NULL;
    }
    memset(buffer, 0, sizeof(buffer));

    // Read of header of ppm file
    fscanf(fp, "%u %u", &xsize, &ysize);
    fscanf(fp, "%u", &color);

    if((3*xsize*ysize) > MAX_SIZE){
        warning_msg("Obrazek je prilis velky.\n");
    }

    while (fgetc(fp) != '\n') ;

    // Alloc memory to store data from ppm picture
    p = malloc(sizeof(struct ppm) + (3*xsize*ysize));
    if(p == NULL){
        error_exit("Chyba alokace pameti.\n");
        fclose(fp);
    }
    p->xsize = xsize;
    p->ysize = ysize;

    // Read of data from ppm picture
    if(fread(p->data, sizeof(char), 3*xsize*ysize, fp) != 3*xsize*ysize){
        warning_msg("Chyba pri cteni dat.\n");
        ppm_free(p);
        fclose(fp);
        exit(1);
    }
    
    fclose(fp);

    return p;
}

// Free of memory used to store ppm data
void ppm_free(struct ppm *p){
    free(p);
}