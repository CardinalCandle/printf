#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
 * print_int - prints an integer.
 * @arg: argument
 * Return: 0
 */
int print_int(va_list arg)
{
	unsigned int div = 1, i, r, chars = 0;
	int n = va_arg(arg, int);

	if (n < 0)
	{
		_putchar('-');
		chars++;
		n *= -1;
	}

	for (i = 0; n / div > 9; i++, div *= 10)
	;

	for (; div >= 1; n %= div, div /= 10, chars++)
	{
		r = n / div;
		_putchar('0' + r);
	}
	return (chars);
}



/**
 * print_unsigned - prints an unsigned int.
 * @arg: argument
 * Return: 0
 */
int print_unsigned(va_list arg)
{
	int div = 1, i, r;
	unsigned int n = va_arg(arg, unsigned int);

	for (i = 0; n / div > 9; i++, div *= 10)
	;

	for (; div >= 1; n %= div, div /= 10)
	{
		r = n / div;
		_putchar('0' + r);
	}
	return (++i);
}
