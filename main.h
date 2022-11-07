#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	_putnbr_runtime(long v, int *r);
int	_putnbr(int v);
int	_printf_char(va_list l);
int	_printf_string(va_list l);
int	_print_integer(va_list l);
int	_printf(const char *format, ...);

#endif
