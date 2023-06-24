#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UF(x) (void)(x)

/**
 * struct fmt - Struct op
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_chr(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_per(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsig(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexdec(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_nonprint(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flg(const char *format, int *i);
int get_wid(const char *format, int *i, va_list list);
int get_prec(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_ptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_print(char);
int append_hex(char, char[], int);
int is_digit(char);

long int convert_num(long int num, int size);
long int convert_unsig(unsigned long int num, int size);

#endif
