#include "main.h"

/**
 * context_new - function
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
 * context_free - function
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

	context_flush(ctx);
	if (ctx->b)
		buffer_free(ctx->b);

	free(ctx);
	return (0);
}

/**
 * context_flush - function
 * @ctx: context_t ptr
 *
 * Return: context_t ptr
*/
context_t	*context_flush(context_t *ctx)
{
	if (!ctx)
		return (0);
	if (!ctx->b)
		return (0);
	buffer_flush(ctx->b);
	return (ctx);
}

/**
 * context_init_handlers - function
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
 * context_write - function
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
