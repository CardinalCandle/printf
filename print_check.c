#include "main.h"

/**
 * is_print - Checks if a char is printable
 * @c: char
 * Return: 1 if c is printable, otherwise 0
 */
int is_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * append_hex - Append ASCII in hexadecimal code to buffer
 * @buffer: array
 * @i: Index at which to start appending.
 * @ascii: ASCII CODE.
 * Return: Always 3
 */
int append_hex(char ascii, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii / 16];
	buffer[i] = map_to[ascii % 16];
	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_num - Casts a number to the specified size
 * @n: Number
 * @size: size
 * Return: Cast value of num
 */
long int convert_num(long int n, int size)
{
	if (size == 2)
		return (n);
	else if (size == 1)
		return ((short)n);
	return ((int)n);
}

/**
 * convert_unsig - Casts a number to the specified size
 * @n: Number
 * @size: size
 * Return: Casted value of num
 */
long int convert_unsig(unsigned long int n, int size)
{
	if (size == 2)
		return (n);
	else if (size == 1)
		return ((unsigned short)n);
	return ((unsigned int)n);
}
