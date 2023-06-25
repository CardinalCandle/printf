#include "main.h"

/**
 * print_chr - Prints a char
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: Width
 * @precision: precision
 * @size: size
 * Return: Number of chars printed
 */
int print_chr(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_str - Prints a string
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UF(buffer);
	UF(flags);
	UF(width);
	UF(precision);
	UF(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & 1)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_per - Prints a percent sign
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_per(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UF(types);
	UF(buffer);
	UF(flags);
	UF(width);
	UF(precision);
	UF(size);
	return (write(1, "%%", 1));
}


/**
 * print_int - Print int
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 1024 - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_num(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[1024 - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}


/**
 * print_bin - Prints an unsigned number
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Numbers of characters
 */
int print_bin(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UF(buffer);
	UF(flags);
	UF(width);
	UF(precision);
	UF(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
