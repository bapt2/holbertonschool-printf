#include "main.h"

/**
 * _printf_handler_integer - function
 * @ctx: context_t ptr
*/
void	_printf_handler_integer(context_t *ctx)
{
	int	v;

	v = (int) va_arg(ctx->l, int);
	_putnbr(ctx, v, 1, "0123456789");
	ctx->i += 1;
}

/**
 * _printf_handler_unsigned - function
 * @ctx: context_t ptr
*/
void	_printf_handler_unsigned(context_t *ctx)
{
	unsigned int	v;

	v = (unsigned int) va_arg(ctx->l, unsigned int);
	_putnbr(ctx, v, 0, "0123456789");
	ctx->i += 1;
}

/**
 * _printf_handler_binary - function
 * @ctx: context_t ptr
*/
void	_printf_handler_binary(context_t *ctx)
{
	unsigned int	v;

	v = (unsigned int) va_arg(ctx->l, unsigned int);
	_putnbr(ctx, v, 0, "01");
	ctx->i += 1;
}

/**
 * _printf_handler_octal - function
 * @ctx: context_t ptr
*/
void	_printf_handler_octal(context_t *ctx)
{
	unsigned int	v;

	v = (unsigned int) va_arg(ctx->l, unsigned int);
	_putnbr(ctx, v, 0, "01234567");
	ctx->i += 1;
}

/**
 * _printf_handler_percent - function
 * @ctx: context_t ptr
*/
void	_printf_handler_percent(context_t *ctx)
{
	char	v;

	v = '%';
	context_write(ctx, &v, 1);
	ctx->i += 1;
}
