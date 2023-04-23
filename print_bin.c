#include "main.h"
/**
 * print_bin - prints binary
 * @n: number
 * @p: # of printed
 */
void print_bin(unsigned int n, unsigned int *p)
{
	if (n > 1)
	{
		*p++;
		print_binary(n >> 1, p);
	}
	_putchar((n & 1) + '0');
}
