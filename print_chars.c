#include "main.h"
/**
 * print_char - writes the character c to stdout
 * @arg: argument
 * Return: 1 or -1.
 */
int print_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

/**
 * print_upper - prints a string with an uppercase specifier
 * @arg: argument
 * Return: number of character printed
 */

int print_upper(va_list arg)
{
	int i;
	char *str = va_arg(arg, char*);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (i < 16)
				_putchar('0');
			print_unsignedIntToHex(str[i], 'A');
		}
		else
			_putchar(str[i]);
	}
	return (i);
}
/**
 * print_lower - prints a string with a `s` (lower case) specifier
 * @arg: argument
 * Return: number of character printed
 */
int print_lower(va_list arg)
{
	int i;
	char *str = va_arg(arg, char*);

	if (str == NULL)
		str = "(null)";
	else if (*str == '\0')
		return (-1);

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (i);
}
