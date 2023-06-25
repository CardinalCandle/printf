#include "main.h"

void print_buff(char buffer[], int *buff_ind);

/**
 * _printf - main function
 * @format: print format
 * Return: Printed characters.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[1024];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == 1024)
				print_buff(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buff(buffer, &buff_ind);
			flags = get_flg(format, &i);
			width = get_wid(format, &i, list);
			precision = get_prec(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buff(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buff - Prints the contents of the buffer, so long as it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, in length.
 */
void print_buff(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

#include "main.h"

/**
 * get_flg - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: parameter
 * Return: flags
 */
int get_flg(const char *format, int *i)
{
	int j, curr_i, flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {1, 2, 4, 8, 16, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
		break;
	}

	*i = curr_i - 1;

	return (flags);
}

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments
 * @ind: ind
 * @buffer: Buffer array
 * @flags: active flags
 * @width: get width.
 * @precision: precision
 * @size: size
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_chr}, {'s', print_str}, {'%', print_per},
		{'i', print_int}, {'d', print_int}, {'b', print_bin},
		{'u', print_unsig}, {'o', print_oct}, {'x', print_hexdec},
		{'X', print_hexa_upper}, {'p', print_ptr}, {'S', print_nonprint},
		{'r', print_rev}, {'R', print_rot13}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
