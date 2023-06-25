#include "main.h"

/**
 * get_prec - Calculates the precision for printing
 * @format: Formatted str
 * @i: arguments to be printed.
 * @list: arg list
 * Return: Precision
 */
int get_prec(const char *format, int *i, va_list list)
{
	int j = *i + 1;
	int precision = -1;

	if (format[j] != '.')
		return (precision);
	precision = 0;
	for (j += 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			precision *= 10;
			precision += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = j - 1;
	return (precision);
}

/**
 * get_size - gets the size to cast the argument
 * @format: Formatted str
 * @i: arg list
 * Return: Precision
 */
int get_size(const char *format, int *i)
{
	int j = *i + 1;
	int s = 0;

	if (format[j] == 'l')
		s = 2;
	else if (format[j] == 'h')
		s = 1;
	if (s == 0)
		*i = j - 1;
	else
		*i = j;
	return (s);
}

/**
 * get_wid - gets the width for printing
 * @format: Formatted str
 * @i: arg list
 * @list: arg list
 * Return: width
 */
int get_wid(const char *format, int *i, va_list list)
{
	int j;
	int w = 0;

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			w *= 10;
			w += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			w = va_arg(list, int);
			break;
		}
		else
		break;
	}
	*i = j - 1;
	return (w);
}
