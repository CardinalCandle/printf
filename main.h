#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>
int _printf(const char *format, ...);
int handle_conversion_specifier(const char **format, va_list arg_list);
int print_char(char c);
int print_string(char *str);
#endif
