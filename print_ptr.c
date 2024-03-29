#include "main.h"

/**
 * print_ptr - Prints the value of a pointer variable
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number of chars printed.
 */
int print_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	{
	char extra_c = 0, padd = ' ';
	int ind = 1024 - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UF(width);
	UF(size);
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[1024 - 1] = '\0';
	UF(precision);
	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length += 1;
	}
	if ((flags & 4) && !(flags & 1))
		padd = '0';
	if (flags & 2)
		extra_c = '+', length += 1;
	else if (flags & 16)
		extra_c = ' ', length += 1;
	ind += 1;
	return (write_ptr(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_nonprint - Prints ascii codes in hexa of non printable chars
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_nonprint(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	{
	int i = 0, off = 0;
	char *str = va_arg(types, char *);

	UF(flags);
	UF(width);
	UF(precision);
	UF(size);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_print(str[i]))
			buffer[i + off] = str[i];
		else
			off += append_hex(str[i], buffer, i + off);
		i += 1;
	}

	buffer[i + off] = '\0';
	return (write(1, buffer, i + off));
}

/**
 * print_rev - Prints string in reverse.
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars
 */
int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	{
	char *str, z;
	int i, count = 0;

	UF(buffer);
	UF(flags);
	UF(width);
	UF(size);
	str = va_arg(types, char *);
	if (str == NULL)
	{
		UF(precision);
		str = ")Null(";
	}
	for (i = 0; str[i]; i += 1)
		;
	for (i = i - 1; i >= 0; i -= 1)
	{
		z = str[i];
		write(1, &z, 1);
		count += 1;
	}
	return (count);
}

/**
 * print_rot13 - Print a string in ceasar cipher.
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Num of chars printed
 */
int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str, x;
	unsigned int i, j;
	int count;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	count = 0;
	str = va_arg(types, char *);
	UF(buffer);
	UF(flags);
	UF(width);
	UF(precision);
	UF(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i += 1)
	{
		for (j = 0; in[j]; j += 1)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count += 1;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count += 1;
		}
	}
	return (count);
}
