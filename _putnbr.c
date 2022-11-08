#include "main.h"

/**
 * _putnbr_runtime - function
 * @v: long
 * @r: int ptr
*/
void	_putnbr_runtime(long v, int *r)
{
	char	c;

	if (v < 0)
	{
		c = '-';
		*r += write(1, &c, 1);
		_putnbr_runtime(-v, r);
	}
	else if (v < 10)
	{
		c = '0' + v;
		*r += write(1, &c, 1);
	}
	else
	{
		_putnbr_runtime(v / 10, r);
		_putnbr_runtime(v % 10, r);
	}
}

/**
 * _putnbr - function
 * @v: int
 *
 * Return: int
*/
int	_putnbr(int v)
{
	int	r;

	r = 0;
	_putnbr_runtime((long) v, &r);
	return (r);
}
