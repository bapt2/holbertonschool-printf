#include "main.h"
#include "typestr.h"

/**
 * _printf_handler_integer - handles %d and %i
 * @ctx: context_t ptr
*/
void	_printf_handler_integer(context_t *ctx)
{
	short	vx;
	int	vy;
	long	vz;

	if (ctx->ol)
	{
		vz = (long) va_arg(ctx->l, long);
		_putnbr(ctx, vz, 1, "0123456789");
	}
	else if (ctx->oh)
	{
		vx = (short) va_arg(ctx->l, int);
		_putnbr(ctx, vx, 1, "0123456789");
	}
	else
	{
		vy = (int) va_arg(ctx->l, int);
		_putnbr(ctx, vy, 1, "0123456789");
	}
}

/**
 * _printf_handler_unsigned - handles %u
 * @ctx: context_t ptr
*/
void	_printf_handler_unsigned(context_t *ctx)
{
	unsigned short	vx;
	unsigned int	vy;
	unsigned long	vz;

	if (ctx->ol)
	{
		vz = (unsigned long) va_arg(ctx->l, unsigned long);
		_putnbr(ctx, vz, 0, "0123456789");
	}
	else if (ctx->oh)
	{
		vx = (unsigned short) va_arg(ctx->l, unsigned int);
		_putnbr(ctx, vx, 0, "0123456789");
	}
	else
	{
		vy = (unsigned int) va_arg(ctx->l, unsigned int);
		_putnbr(ctx, vy, 0, "0123456789");
	}
}

/**
 * _printf_handler_binary - handles %b
 * @ctx: context_t ptr
*/
void	_printf_handler_binary(context_t *ctx)
{
	unsigned int	v;

	v = (unsigned int) va_arg(ctx->l, unsigned int);
	_putnbr(ctx, v, 0, "01");
}

/**
 * _printf_handler_octal - handles %o
 * @ctx: context_t ptr
*/
void	_printf_handler_octal(context_t *ctx)
{
	unsigned short	vx;
	unsigned int	vy;
	unsigned long	vz;

	if (ctx->ol)
	{
		vz = (unsigned long) va_arg(ctx->l, unsigned long);
		_putnbr(ctx, vz, 0, "01234567");
	}
	else if (ctx->oh)
	{
		vx = (unsigned short) va_arg(ctx->l, unsigned int);
		_putnbr(ctx, vx, 0, "01234567");
	}
	else
	{
		vy = (unsigned int) va_arg(ctx->l, unsigned int);
		_putnbr(ctx, vy, 0, "01234567");
	}
}

/**
 * _printf_handler_percent - handles %%
 * @ctx: context_t ptr
*/
void	_printf_handler_percent(context_t *ctx)
{
	char	v;

	v = '%';
	context_write(ctx, &v, 1);
}
