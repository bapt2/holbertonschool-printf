#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct context	context_t;
typedef struct handler	handler_t;
typedef struct buffer	buffer_t;

# define i8  int8_t
# define u8  uint8_t
# define i32 int32_t
# define u32 uint32_t
# define i64 int64_t
# define u64 uint64_t

/**
 * struct buffer - struct
 * @size: i32
 * @curr: i32
 * @body: str
*/
struct buffer
{
	i32	size;
	i32	curr;
	char	*body;
};

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
 * @f: const char ptr
 * @h: handler_t ptr
 * @b: buffer_t ptr
 * @l: va_list
 * @r: i32
 * @i: i32
*/
struct context
{
	const char	*f;
	handler_t	*h;
	buffer_t	*b;
	va_list		l;
	i32		r;
	i32		i;
};

void		*malloc_try(size_t size);
size_t		_strlen(const char *s);
char		*_strrev(char *s);
char		*_strdup(char *s);
void		_putnbr(context_t *ctx, u64 val, i32 sign, char *base);

context_t	*context_new(context_t *ctx);
context_t	*context_free(context_t *ctx);
context_t	*context_init_handlers(context_t *ctx);
context_t	*context_write(context_t *ctx, void *src, i32 size);
i32		context_consume(context_t *ctx);

buffer_t	*buffer_new(buffer_t *buf);
buffer_t	*buffer_free(buffer_t *buf);
buffer_t	*buffer_flush(buffer_t *buf);
i32		buffer_append_byte(buffer_t *buf, u8 v);
i32		buffer_append_bytes(buffer_t *buf, void *src, i32 size);

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
void		_printf_handler_ascii(context_t *ctx);
void		_printf_handler_pointer(context_t *ctx);
void		_printf_handler_string_reversed(context_t *ctx);

void		_printf_runtime(context_t *ctx);
i32		_printf(const char *format, ...);

#endif
