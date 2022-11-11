#include "main.h"
#include "typestr.h"

/**
 * _printf_handler_char - handles %c
 * @ctx: context_t ptr
*/
void	_printf_handler_char(context_t *ctx)
{
	unsigned char	v;

	v = (unsigned char) va_arg(ctx->l, int);
	context_write(ctx, &v, 1);
}

/**
 * _printf_handler_string - handles %s
 * @ctx: context_t ptr
*/
void	_printf_handler_string(context_t *ctx)
{
	char	*v;

	v = (char *) va_arg(ctx->l, char *);
	if (!v)
		v = "(null)";

	context_write(ctx, v, _strlen(v));
}

/**
 * _printf_handler_string_reversed - handles %r
 * @ctx: context_t ptr
*/
void	_printf_handler_string_reversed(context_t *ctx)
{
	char	*v;

	v = (char *) va_arg(ctx->l, char *);
	if (!v)
		v = _strdup("(null)");
	else
		v = _strrev(_strdup(v));
	context_write(ctx, v, _strlen(v));
	free(v);
}

/**
 * _printf_handler_ascii - handles %S
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
}
