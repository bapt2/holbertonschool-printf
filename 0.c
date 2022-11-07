#include "main.h"

/**
 * _printf_char - function
 * @l: va_list
 *
 * Return: characters printed
 */
int	_printf_char(va_list l)
{
	unsigned char	v;

	v = (unsigned char) va_arg(l, int);
	write(1, &v, 1);
	return (1);
}

/**
 * _printf_string - function
 * @l: va_list
 *
 * Return: characters printed
 */
int	_printf_string(va_list l)
{
	char	*v;
	int	x;
	char	*n;

	n = "(null)";
	v = (char *) va_arg(l, char *);
	if (!v)
		return (write(1, n, 6));
	for (x = 0; v[x]; x++)
		;
	write(1, v, x);
	return (x);
}

/**
 *_printf - function that produces output according to a format
 *
 *@format: const char ptr
 *Return: characters printed
 */
int _printf(const char *format, ...)
{
	int	r;
	int	x;
	va_list	l;

	if (!format)
		return (-1);
	va_start(l, format);
	r = 0;
	for (x = 0; format[x]; x++)
	{
		if (format[x] == '%')
		{
			switch (format[x + 1])
			{
			case 'c':
				r += _printf_char(l);
				x++;
				break;
			case 's':
				r += _printf_string(l);
				x++;
				break;
			case '%':
				r += write(1, &format[x], 1);
				x++;
				break;
			case '\0':
				break;
			default:
				r += write(1, &format[x], 1);
				break;
			}
		}
		else
			r += write(1, &format[x], 1);
	}
	va_end(l);
	return (r);
}

