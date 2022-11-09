#include "main.h"

/**
 * _printf_handler_char - function
 * @ctx: context_t ptr
*/
void	_printf_handler_char(context_t *ctx)
{
	unsigned char	v;

	v = (unsigned char) va_arg(ctx->l, int);
	context_write(ctx, &v, 1);
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
		v = "(null)";

	context_write(ctx, v, _strlen(v));
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
	context_write(ctx, &v, 1);
	ctx->i += 0;
}

/**
 * _printf_handler_ascii - function
 * @ctx: context_t ptr
*/
void	_printf_handler_ascii(context_t *ctx)
{
	str	v;
	i32	x;
	char	c;

	v = (str) va_arg(ctx->l, str);
	if (!v)
	{
		v = "(null)";
		context_write(ctx, v, _strlen(v));
	}
	else
	{
		for (x = 0; v[x]; x++)
		{
			if ((!v[x]) || (v[x] < 32) || (v[x] >= 127))
			{
				c = '\\';
				context_write(ctx, &c, 1);
				c = 'x';
				context_write(ctx, &c, 1);
				c = "0123456789ABCDEF"[v[x] / 16];
				context_write(ctx, &c, 1);
				c = "0123456789ABCDEF"[v[x] % 16];
				context_write(ctx, &c, 1);
			}
			else
				context_write(ctx, &v[x], 1);
		}
	}
	ctx->i += 1;
}
