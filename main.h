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
int _putchar(char c);
int handle_specifier(const char *format, va_list args, int printed);
int _printf(const char *format, ...);
int print_str(va_list args, int printed);
int print_int(va_list args, int printed);
#endif
