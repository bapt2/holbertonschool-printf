#include "main.h"
#include "typestr.h"

/**
 * _printf_handler_hexadecimal_lower - handles %x
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
 * _printf_handler_hexadecimal_upper - handles %X
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
 * _printf_handler_pointer - handles %p
 * @ctx: context_t ptr
*/
void	_printf_handler_pointer(context_t *ctx)
{
	void	*v;
	str	s;

	v = (void *) va_arg(ctx->l, void *);
	if (!v)
	{
		s = "(nil)";
		context_write(ctx, s, _strlen(s));
	}
	else
	{
		s = "0x";
		context_write(ctx, s, _strlen(s));
		_putnbr(ctx, (u64) v, 0, "0123456789abcdef");
	}
	ctx->i += 1;
}
