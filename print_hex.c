#include "main.h"

/**
 * print_unsig - Prints an unsigned number
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number of chars printed.
 */
int print_unsig(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	{
	int i = 1024 - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_unsig(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[1024 - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_oct - Prints an unsigned number in octal notation
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars
 */
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	{
	int i = 1024 - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UF(width);
	num = convert_unsig(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[1024 - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & 8 && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/**
 * print_hexdec - Prints an unsigned number in hexa (0x) notation
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexdec(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
	}


/**
 * print_hexa_upper - Prints unsigned number in hexa (upper) notation
 * @types: arg list
 * @buffer: array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
	{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
	}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: arg list
 * @map_to: Array of values to map to
 * @buffer: array
 * @flags: active flags
 * @flag_ch: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = 1024 - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UF(width);
	num = convert_unsig(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[1024 - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & 8 && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
