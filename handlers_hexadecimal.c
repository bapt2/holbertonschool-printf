#include "main.h"

/**
 * _printf_handler_hexadecimal_lower - function
 * @ctx: context_t ptr
*/
void	_printf_handler_hexadecimal_lower(context_t *ctx)
{
	unsigned int	v;

	v = (unsigned int) va_arg(ctx->l, unsigned int);
	_putnbr(ctx, v, 0, "0123456789abcdef");
	ctx->i += 1;
}

/**
 * _printf_handler_hexadecimal_upper - function
 * @ctx: context_t ptr
*/
void	_printf_handler_hexadecimal_upper(context_t *ctx)
{
	unsigned int	v;

	v = (unsigned int) va_arg(ctx->l, unsigned int);
	_putnbr(ctx, v, 0, "0123456789ABCDEF");
	ctx->i += 1;
}

/**
 * _printf_handler_pointer - function
 * @ctx: context_t ptr
*/
void	_printf_handler_pointer(context_t *ctx)
{
	void	*v;
	str	s;

	v = (void *) va_arg(ctx->l, void *);
	s = "0x";
	context_write(ctx, s, _strlen(s));
	_putnbr(ctx, (u64) v, 0, "0123456789ABCDEF");
	ctx->i += 1;
}
