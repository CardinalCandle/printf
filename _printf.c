#include <stdarg.h>
#include <unistd.h>
int print_char(va_list args)
{
	char c = (char) va_arg(args, int);
	return write(1, &c, 1);
}

int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++)
		count += write(1, &str[i], 1);
	return count;
}

int print_int(va_list args)
{
    int n = va_arg(args, int);
    char str[11];
    int i = 0, count = 0;
    if (n < 0)
    {
        count += write(1, "-", 1);
        n = -n;
    }
    while (n > 9)
    {
        str[i++] = n % 10 + '0';
        n /= 10;
    }
    str[i++] = n + '0';
    while (--i >= 0)
        count += write(1, &str[i], 1);
    return count;
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = 0;
    for (int i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    count += print_char(args);
                    break;
                case 's':
                    count += print_str(args);
                    break;
                case '%':
                    count += write(1, &format[i], 1);
                    break;
                case 'd':
                case 'i':
                    count += print_int(args);
                    break;
            }
        }
        else
            count += write(1, &format[i], 1);
    }
    va_end(args);
    return count;
}
