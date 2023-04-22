#include "main.h"

/**
* handle_specifier - selects the appropriate specifiers
* @args: number of arguements
* @p: the printed characters
* @format: the format specifier
* Return: printed characters
*/
int handle_specifier(const char *format, va_list args, int printed)
{
	switch (*format)
	{
		case 'd':
		case 'i':
			printed = print_int(args, printed);
			break;
		case 'c':
			_putchar(va_arg(args, int));
			printed++;
			break;
		case 'S':
		case 's':
			printed = print_str(args, printed);
			break;
		case '%':
			_putchar('%');
			printed++;
			break;
		default:
			break;
	}
	return (printed);
}

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * Return: the formated string
 */
int _printf(const char *format, ...)
{
	int printed = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			printed = handle_specifier(format, args, printed);
			format++;
		}
		else
		{
			_putchar(*format);
			printed++;
			format++;
		}
	}
	va_end(args);
	return (printed);
	}

/**
 * print_str - prints a string
 * @args: number of arguments
 * @printed: number of printed characters
 * Return: printed characters
 */

int print_str(va_list args, int printed)
{
	char *s = va_arg(args, char *);

	while (*s != '\0')
	{
		_putchar(*s);
		printed++;
		s++;
	}
	return (printed);
}

/**
 * printf_integer - prints integer
 * @args: # of arguments
 * @printed: the printed characters
 * Return: printed charcaters
 */

int print_int(va_list args, int printed)
{
	int num = va_arg(args, int);
	int temp = num;
	int d = 0, pow10, i;

	if (num < 0)
	{
		printed += _putchar('-');
		num = -num;
		temp = num;
	}

	do
	{
		d++;
		temp /= 10;
	} while (temp != 0);

	while (d > 0)
	{
		pow10 = 1;
		for (i = 1; i < d; i++)
		{
			pow10 *= 10;
		}
		d = num / pow10;
		printed += _putchar(d + '0');
		num -= d * pow10;
		d--;
	}
	return (printed);
}
