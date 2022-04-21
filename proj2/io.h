// Name: io.h
// IJC_DU2 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 10.04.2022



#ifndef __IO_H__
#define __IO_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// reads file word by word
int read_word(char *s, int max, FILE *f);


#endif // __IO_H__