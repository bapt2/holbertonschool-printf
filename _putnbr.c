#include "main.h"

/**
 * _putnbr_runtime_i64 - function
 * @r: i32 ptr
 * @v: i64
 * @b: str
 * @l: i32
*/
void	_putnbr_runtime_i64(i32 *r, i64 v, str b, i32 l)
{
	char	c;

	if (v < 0)
	{
		c = '-';
		*r += write(1, &c, 1);
		_putnbr_runtime_i64(r, -v, b, l);
	}
	else if (v < l)
	{
		c = b[v];
		*r += write(1, &c, 1);
	}
	else
	{
		_putnbr_runtime_i64(r, v / l, b, l);
		_putnbr_runtime_i64(r, v % l, b, l);
	}
}

/**
 * _putnbr_runtime_u64 - function
 * @r: i32 ptr
 * @v: u4
 * @b: str
 * @l: i32
*/
void	_putnbr_runtime_u64(i32 *r, u64 v, str b, i32 l)
{
	char	c;

	if (v < _strlen(b))
	{
		c = b[v];
		*r += write(1, &c, 1);
	}
	else
	{
		_putnbr_runtime_u64(r, v / l, b, l);
		_putnbr_runtime_u64(r, v % l, b, l);
	}
}

/**
 * _putnbr - function
 * @val: u64
 * @size: i32
 * @sign: i32
 * @base: str
 * Return: int
*/
i32	_putnbr(u64 val, i32 size, i32 sign, str base)
{
	i32	r;
	i32	l;

	(void) size;
	r = 0;
	l = _strlen(base);
	if (l < 1)
		return (0);
	if (sign)
	{
		_putnbr_runtime_i64(&r, (i64) val, base, _strlen(base));
	}
	else
	{
		_putnbr_runtime_u64(&r, val, base, _strlen(base));
	}
	return (r);
}
