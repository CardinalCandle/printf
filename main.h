#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
int _printf(const char *format, ...);
int handle_conversion_specifier(const char **format, va_list arg_list);
int print_char(char c);
int print_string(char *str);
int handle_specifier(char specifier, va_list ap);
int print_unknown_specifier(char c);

void reverse(char s[]);
void _itoa(int n);
#endif
