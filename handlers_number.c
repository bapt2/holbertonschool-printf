#include "main.h"

/**
 * _printf_handler_integer - function
 * @ctx: context_t ptr
*/
void	_printf_handler_integer(context_t *ctx)
{
	int	v;

	v = (int) va_arg(ctx->l, int);
	ctx->r += _putnbr(v, sizeof(int), 1, "0123456789");
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
	ctx->r += _putnbr(v, sizeof(unsigned int), 0, "01");
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
	ctx->r += write(1, &v, 1);
	ctx->i += 1;
}
