#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_unsignedToBinary - prints an integer.
 * @arg: argument
 * Return: 0
 */
int print_unsignedToBinary(va_list arg)
{
	unsigned int p, n = va_arg(arg, unsigned int);

	print_bin(n, &p);
	print_bin(n, &p);
	return (p);
}


/**
 * print_oct - prints number in octal base.
 * @arg: list containing octal number to be printed
 * Return: number of chars
 */
int print_oct(va_list arg)
{
	unsigned int copy, num = va_arg(arg, unsigned int);
	char *octa;
	int i, j, chars = 0;

	if (num == 0)
		return (_putchar('0'));
	for (copy = num; copy != 0; j++)
	{
		copy = copy / 8;
	}
	octa = malloc(j);
	if (!octa)
		return (-1);

	for (i = j - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}

	for (i = 0; i < j && octa[i] == '0'; i++)
		;
	for (; i < j; i++)
	{
		_putchar(octa[i]);
		chars++;
	}
	free(octa);
	return (chars);
}

/**
 * print_unsignedIntToHex - prints unsigned int to hexadecimal.
 * @num: number to print
 * @c: char upper or lower
 * Return: number or char printed
 */
int print_unsignedIntToHex(unsigned int num, char c)
{
	unsigned int num2;
	int i, j, remainder, chars = 0;
	char *hex;

	for (num2 = num; num2 != 0; chars++, num2 /= 16)
	;

	hex = malloc(chars);
	for (i = 0; num != 0; i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			hex[i] = remainder + '0';
		else
			hex[i] = remainder - 10 + c;
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(hex[j]);
	free(hex);
	return (chars);
}
