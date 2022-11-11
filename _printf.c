#include "main.h"
#include "typestr.h"

/**
 * _printf_runtime - function
 * @ctx: context_t ptr
*/
void	_printf_runtime(context_t *ctx)
{
	i32	x;

	for (ctx->i = 0; ctx->f[ctx->i]; ctx->i++)
	{
		if (ctx->f[ctx->i] == '%')
		{
			for (x = 0; ctx->h[x].f; x++)
			{
				if (ctx->h[x].c == ctx->f[ctx->i + 1])
				{
					ctx->h[x].f(ctx);
					break;
				}
			}
			if (!ctx->h[x].f)
			{
				_printf_handler_unknown(ctx);
			}
		}
		else
		{
			_printf_handler_normal(ctx);
		}
	}
}

/**
 * _printf - function
 * @format: const char ptr
 *
 * Return: characters printed
*/
int	_printf(const char *format, ...)
{
	i32		r;
	context_t	*ctx;

	if (!format)
		return (-1);

	ctx = context_new(0);
	ctx->f = format;

	va_start(ctx->l, format);

	_printf_runtime(ctx);

	va_end(ctx->l);

	r = ctx->r;
	context_free(ctx);
	return (r);
}
