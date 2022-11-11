#include "main.h"
#include "typestr.h"

/**
 * _printf_handler_hexadecimal_lower - handles %x
 * @ctx: context_t ptr
*/
void	_printf_handler_hexadecimal_lower(context_t *ctx)
{
	unsigned short	vx;
	unsigned int	vy;
	unsigned long	vz;

	if (ctx->ol)
	{
		vz = (unsigned long) va_arg(ctx->l, unsigned long);
		_putnbr(ctx, vz, 0, "0123456789abcdef");
	}
	else if (ctx->oh)
	{
		vx = (unsigned short) va_arg(ctx->l, unsigned int);
		_putnbr(ctx, vx, 0, "0123456789abcdef");
	}
	else
	{
		vy = (unsigned int) va_arg(ctx->l, unsigned int);
		_putnbr(ctx, vy, 0, "0123456789abcdef");
	}
}

/**
 * _printf_handler_hexadecimal_upper - handles %X
 * @ctx: context_t ptr
*/
void	_printf_handler_hexadecimal_upper(context_t *ctx)
{
	unsigned short	vx;
	unsigned int	vy;
	unsigned long	vz;

	if (ctx->ol)
	{
		vz = (unsigned long) va_arg(ctx->l, unsigned long);
		_putnbr(ctx, vz, 0, "0123456789ABCDEF");
	}
	else if (ctx->oh)
	{
		vx = (unsigned short) va_arg(ctx->l, unsigned int);
		_putnbr(ctx, vx, 0, "0123456789ABCDEF");
	}
	else
	{
		vy = (unsigned int) va_arg(ctx->l, unsigned int);
		_putnbr(ctx, vy, 0, "0123456789ABCDEF");
	}
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
}
