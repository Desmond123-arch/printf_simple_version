#ifndef MAIN_H
#define MAIN_H
#include <stdint.h>
#include <cstdarg>
#include <stdio.h>
//function prototypes
void unsigned_number_tostring(uint64_t number, int base, char* buffer);
void number_to_string(int64_t number, int base, char* buffer);
void vprintk(const char* fmt, va_list args);
void printk(const char* fmt, ...);
#endif /* MAIN_H */
