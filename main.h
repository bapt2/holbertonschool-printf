#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	_printf_char(va_list l);
int	_printf_string(va_list l);
int	_printf(const char *format, ...);

#endif
