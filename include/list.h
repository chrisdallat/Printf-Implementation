#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifndef PRINTF_H
#define PRINTF_H

int my_printf(char *format, ...);
char my_putchar(char c);
int my_putstr(char *string);
char *my_itoa(int num, char *str, int base);
void my_reverse(char str[], int len);
char *my_utoa(unsigned int number, char *string, int base);
char *to_hex(unsigned long number, char* string);

#endif

