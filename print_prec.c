#include "main.h"

/**
 * get_prec - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_prec(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int s = 0;

	if (format[curr_i] == 'l')
		s = 2;
	else if (format[curr_i] == 'h')
		s = 1;

	if (s == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (s);
}

/**
 * get_wid - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_wid(const char *format, int *i, va_list list)
{
	int curr_i;
	int w = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			w *= 10;
			w += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			w = va_arg(list, int);
			break;
		}
		else
		break;
	}

	*i = curr_i - 1;

	return (w);
}
