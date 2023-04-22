#include "main.h"

int handle_specifier(char specifier, va_list ap)
{
    int len = 0;

    switch (specifier)
    {
        case 's':
        case 'S':
            len += print_string(va_arg(ap, char *));
            break;
        case 'c':
        case 'C':
            len += print_char(va_arg(ap, int));
            break;
        case 'i':
        case 'd':
            len += printf("%i", va_arg(ap, int));
            break;
        case '%':
            len += write(1, "%", 1);
            break;
        default:
            len += print_unknown_specifier(specifier);
    }

    return len;
}

int print_unknown_specifier(char c)
{
    write(1, "%", 1);
    write(1, &c, 1);
    return (2);
}

int print_string(char *s)
{
    if (s == NULL)
        return (write(1, "(null)", 6));
    return (write(1, s, strlen(s)));
}

int print_char(char s)
{
    return (write(1, &s, 1));
}

int _printf(const char *format, ...)
{
    int i = 0;
    int len = 0;
    va_list ap;

    va_start(ap, format);
    if (!format)
        return (-1);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                i--;
            else
                len += handle_specifier(format[i], ap);
        }
        else
            len += write(1, &format[i], 1);
        i++;
    }

    va_end(ap);
    return (len);
}
