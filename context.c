#include "main.h"
#include "typestr.h"

/**
 * context_new - creates a new context object
 * @ctx: context_t ptr
 *
 * Return: context_t ptr
*/
context_t	*context_new(context_t *ctx)
{
	if (ctx)
		context_free(ctx);
	ctx = (context_t *) malloc_try(sizeof(context_t));
	ctx->f = 0;
	ctx->h = 0;
	ctx->i = 0;
	ctx->r = 0;
	ctx->b = buffer_new(0);
	context_init_handlers(ctx);
	return (ctx);
}

/**
 * context_free - frees up a context object
 * @ctx: context_t ptr
 *
 * Return: context_t ptr
*/
context_t	*context_free(context_t *ctx)
{
	if (!ctx)
		return (0);

	if (ctx->h)
		free(ctx->h);

	if (ctx->b)
	{
		buffer_flush(ctx->b);
		buffer_free(ctx->b);
	}

	free(ctx);
	return (0);
}

/**
 * context_consume - frees up a context object while returning its result value
 * @ctx: context_t ptr
 *
 * Return: i32
*/
i32	context_consume(context_t *ctx)
{
	i32	r;

	if (!ctx)
		return (0);
	if (!ctx->b)
		return (0);
	r = ctx->r;
	context_free(ctx);
	return (r);
}

/**
 * context_init_handlers - initializes a context object's handlers field
 * @ctx: context_t ptr
 *
 * Return: context_t ptr
*/
context_t	*context_init_handlers(context_t *ctx)
{
	int		x;
	handler_t	h[] = {
		{'c',  _printf_handler_char},
		{'s',  _printf_handler_string},
		{'d',  _printf_handler_integer},
		{'i',  _printf_handler_integer},
		{'%',  _printf_handler_percent},
		{'b',  _printf_handler_binary},
		{'o',  _printf_handler_octal},
		{'u',  _printf_handler_unsigned},
		{'x',  _printf_handler_hexadecimal_lower},
		{'X',  _printf_handler_hexadecimal_upper},
		{'S',  _printf_handler_ascii},
		{'p',  _printf_handler_pointer},
		{'r',  _printf_handler_string_reversed},
		{'\0', _printf_handler_null},
		{'\0', 0},
	};

	if (!ctx)
	{
		return (0);
	}
	for (x = 0; h[x].f; x++)
	{
		;
	}
	ctx->h = (handler_t *) malloc_try(sizeof(handler_t) * ++x);
	for (x = 0; h[x].f; x++)
	{
		ctx->h[x] = h[x];
	}
	ctx->h[x] = h[x];
	return (ctx);
}

/**
 * context_write - copies and writes data to the context object's output buffer
 * @ctx: context_t ptr
 * @src: void ptr
 * @size: i32
 *
 * Return: context_t ptr
*/
context_t	*context_write(context_t *ctx, void *src, i32 size)
{
	if (!ctx)
		return (0);
	if (!ctx->b)
		ctx->r += write(1, src, size);
	else
		ctx->r += buffer_append_bytes(ctx->b, src, size);
	return (ctx);
}
