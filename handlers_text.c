#include "main.h"

/**
 * _printf_handler_char - function
 * @ctx: context_t ptr
*/
void	_printf_handler_char(context_t *ctx)
{
	unsigned char	v;

	v = (unsigned char) va_arg(ctx->l, int);
	context_write(ctx, &v, 1);
	ctx->i += 1;
}

/**
 * _printf_handler_string - function
 * @ctx: context_t ptr
*/
void	_printf_handler_string(context_t *ctx)
{
	char	*v;

	v = (char *) va_arg(ctx->l, char *);
	if (!v)
		v = "(null)";

	context_write(ctx, v, _strlen(v));
	ctx->i += 1;
}

/**
 * _printf_handler_normal - function
 * @ctx: context_t ptr
*/
void	_printf_handler_normal(context_t *ctx)
{
	char	v;

	v = ctx->f[ctx->i];
	context_write(ctx, &v, 1);
	ctx->i += 0;
}
