#include "main.h"

/**
 * _printf_handler_char - function
 * @ctx: context_t ptr
*/
void	_printf_handler_char(context_t *ctx)
{
	unsigned char	v;

	v = (unsigned char) va_arg(ctx->l, int);
	ctx->r += write(1, &v, 1);
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
	{
		ctx->r += write(1, "(null)", 6);
		ctx->i += 1;
		return;
	}
	ctx->r += write(1, v, _strlen(v));
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
	ctx->r += write(1, &v, 1);
	ctx->i += 0;
}
