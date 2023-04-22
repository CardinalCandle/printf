#include "main.h"
/**
 * _printf - very simple printf implementation
 * @format: string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	int num_chars_printed = 0;

	va_start(arg_list, format);

	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
		format++;
		num_chars_printed += handle_conversion_specifier(&format, arg_list);
		}
		else
		{
			putchar(*format);
			num_chars_printed++;
		}
	}

	va_end(arg_list);
	return (num_chars_printed);
}

/**
 * handle_conversion_specifier - handles conversion specifier
 * @format: string
 * @arg_list: variable argument list
 * Return: number of characters printed
 */
int handle_conversion_specifier(const char **format, va_list arg_list)
{
	int num_chars_printed = 0;

	switch (**format)
	{
		case 'c':
			putchar(va_arg(arg_list, int));
			num_chars_printed++;
			break;
		case 's':
			num_chars_printed += printf("%s", va_arg(arg_list, char *));
			break;
		case '%':
			putchar('%');
			num_chars_printed++;
			break;
		case 'd':
		case 'i':
			num_chars_printed += printf("%d", va_arg(arg_list, int));
			break;
		case 'u':
			num_chars_printed += printf("%u", va_arg(arg_list, unsigned int));
			break;
		case 'o':
			num_chars_printed += printf("%o", va_arg(arg_list, int));
			break;
		case 'X':
		case 'x':
			num_chars_printed += printf("%x", va_arg(arg_list, int));
			break;
		case 'p':
			num_chars_printed += printf("%p", va_arg(arg_list, void*));
			break;
		default:
			putchar('%');
			putchar(**format);
			num_chars_printed += 2;
			break;
	}
	return (num_chars_printed);
}
