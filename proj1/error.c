// Name: error.c
// IJC_DU1 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 27.02.2022

#include "error.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// Prints warning message in a format similar to printf function
void warning_msg(const char *fmt, ...){
    va_list arg_list;
    va_start(arg_list, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, arg_list);
    va_end(arg_list);
}

// Prints warning message in a format similar to printf function and end program with exit code 1
void error_exit(const char *fmt, ...){
    va_list arg_list;
    va_start(arg_list, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, arg_list);
    va_end(arg_list);
    exit(1);
}