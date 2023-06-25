#include "main.h"

/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UF(precision);
	UF(size);

	if (flags & 4)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[1024 - 1] = '\0';
		for (i = 0; i < width - 1; i += 1)
			buffer[1024 - i - 2] = padd;

		if (flags & 1)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[1024 - i - 1], width - 1));
		else
			return (write(1, &buffer[1024 - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}


/**
 * write_number - Prints a string
 * @is_negative: arg list
 * @ind: char types.
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 1024 - ind - 1;
	char padd = ' ', extra_ch = 0;

	UF(size);

	if ((flags & 4) && !(flags & 1))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & 2)
		extra_ch = '+';
	else if (flags & 16)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: precision
 * @length: Number length
 * @padd: Padding char
 * @extra_c: Extra char
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == 1024 - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == 1024 - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length += 1;
	if (extra_c != 0)
		length += 1;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i += 1)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & 1 && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & 1) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & 1) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number
 * @ind: Index at buffer
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{

	int length = 1024 - ind - 1, i = 0;
	char padd = ' ';

	UF(is_negative);
	UF(size);

	if (precision == 0 && ind == 1024 - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length += 1;
	}

	if ((flags & 4) && !(flags & 1))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i += 1)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & 1)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_ptr - Write a memory address
 * @buffer: array
 * @ind: Index at buffer
 * @length: Number length
 * @width: width
 * @flags: active flags
 * @padd: Padding char
 * @extra_c: Extra char
 * @padd_start: Padding start
 * Return: Number of written chars.
 */
int write_ptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i += 1)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & 1 && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & 1) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & 1) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], 1024 - ind - 1));
}
