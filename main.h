#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct context	context_t;
typedef struct handler	handler_t;

/**
 * struct handler - struct
 * @c: char
 * @f: void function context_t ptr
*/
struct handler
{
	char	c;
	void	(*f)(context_t *);
};

/**
 * struct context - struct
 * @h: handler_t ptr
 * @f: const char ptr
 * @l: va_list
 * @r: int
 * @i: int
*/
struct context
{
	handler_t	*h;
	const char	*f;
	va_list		l;
	int		r;
	int		i;
};

void		*malloc_try(size_t size);
size_t		_strlen(const char *s);
int		_putnbr(int v);

context_t	*context_new(context_t *ctx);
context_t	*context_free(context_t *ctx);
context_t	*context_init_handlers(context_t *ctx);

void		_printf_handler_normal(context_t *ctx);
void		_printf_handler_char(context_t *ctx);
void		_printf_handler_string(context_t *ctx);
void		_printf_handler_integer(context_t *ctx);
void		_printf_handler_percent(context_t *ctx);
void		_printf_handler_null(context_t *ctx);
void		_printf_handler_unknown(context_t *ctx);

void		_printf_runtime(context_t *ctx);
int		_printf(const char *format, ...);

#endif
