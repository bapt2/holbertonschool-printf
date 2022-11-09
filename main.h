#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct context	context_t;
typedef struct handler	handler_t;

# define i8  int8_t
# define u8  uint8_t
# define i32 int32_t
# define u32 uint32_t
# define i64 int64_t
# define u64 uint64_t
# define str char *

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
i32		_putnbr(u64 val, i32 size, i32 sign, str base);

context_t	*context_new(context_t *ctx);
context_t	*context_free(context_t *ctx);
context_t	*context_init_handlers(context_t *ctx);

void		_printf_handler_normal(context_t *ctx);
void		_printf_handler_char(context_t *ctx);
void		_printf_handler_string(context_t *ctx);
void		_printf_handler_integer(context_t *ctx);
void		_printf_handler_percent(context_t *ctx);
void		_printf_handler_binary(context_t *ctx);
void		_printf_handler_null(context_t *ctx);
void		_printf_handler_unknown(context_t *ctx);
void		_printf_handler_octal(context_t *ctx);
void		_printf_handler_unsigned(context_t *ctx);
void		_printf_handler_hexadecimal_lower(context_t *ctx);
void		_printf_handler_hexadecimal_upper(context_t *ctx);

void		_printf_runtime(context_t *ctx);
int		_printf(const char *format, ...);

#endif
