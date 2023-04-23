#include "main.h"
/**
 * print_hex_main - print hexadecimal numbers
 * @arg: arguments
 * @c: character
 * Return: # digits printed
 */
int print_hex_main(va_list arg, char c)
{
	unsigned int num = va_arg(arg, unsigned int);
	int chars;

	if (num == 0)
		return (_putchar('0'));
	chars = print_unsignedIntToHex(num, c);
	return (chars);
}
/**
 * print_hex_lower - prints a hexadecimal in lower case
 * @arg: list that contains hexadecimal to print
 * Return: # printed
 */
int print_hex_lower(va_list arg)
{
	return (print_hex_main(arg, 'a'));
}

/**
 * print_hex_upper - prints a hexadecimal in upper case
 * @arg: arguments
 * Return: # printed
 */
int print_hex_upper(va_list arg)
{
	return (print_hex_main(arg, 'A'));
}
