#include "main.h"
#include "typestr.h"

/**
 * _putnbr_runtime_i64 - recursive delegate function to _putnbr for signed numbers
 * @ctx: context_t ptr
 * @v: i64
 * @b: str
 * @l: i32
*/
void	_putnbr_runtime_i64(context_t *ctx, i64 v, str b, i32 l)
{
	char	c;

	if (v < 0)
	{
		c = '-';
		context_write(ctx, &c, 1);
		_putnbr_runtime_i64(ctx, -v, b, l);
	}
	else if (v < l)
	{
		c = b[v];
		context_write(ctx, &c, 1);
	}
	else
	{
		_putnbr_runtime_i64(ctx, v / l, b, l);
		_putnbr_runtime_i64(ctx, v % l, b, l);
	}
}

/**
 * _putnbr_runtime_u64 - recursive delegate function to _putnbr for unsigned numbers
 * @ctx: context_t ptr
 * @v: u4
 * @b: str
 * @l: i32
*/
void	_putnbr_runtime_u64(context_t *ctx, u64 v, str b, i32 l)
{
	char	c;

	if (v < _strlen(b))
	{
		c = b[v];
		context_write(ctx, &c, 1);
	}
	else
	{
		_putnbr_runtime_u64(ctx, v / l, b, l);
		_putnbr_runtime_u64(ctx, v % l, b, l);
	}
}

/**
 * _putnbr - prints any <= 64 bits number in a given base
 * @ctx: context_t ptr
 * @val: u64
 * @sign: i32
 * @base: str
*/
void	_putnbr(context_t *ctx, u64 val, i32 sign, str base)
{
	if (!ctx)
		return;
	if (_strlen(base) < 1)
		return;
	if (sign)
		_putnbr_runtime_i64(ctx, (i64) val, base, _strlen(base));
	else
		_putnbr_runtime_u64(ctx, (u64) val, base, _strlen(base));
}
