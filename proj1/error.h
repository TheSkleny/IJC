// Name: error.h
// IJC_DU1 solution - task B
// Author: David Sklenář
// Login: xsklen14
// Faculty: FIT
// Compiled: gcc 9.2.0
// Start date: 27.02.2022

#ifndef ERROR_H
#define ERROR_H

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);

#endif //ERROR_H