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
	free(ctx->h);
	free(ctx);
	return (0);
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
