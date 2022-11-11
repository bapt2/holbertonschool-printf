#include "main.h"
#include "typestr.h"

/**
 * _printf_runtime - delegate function of _printf
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
 * _printf - prints @format to stdout using format specifiers
 * @format: const char ptr
 *
 * Return: characters printed
*/
i32	_printf(const char *format, ...)
{
	context_t	*ctx;

	if (!format)
		return (-1);

	ctx = context_new(0);
	ctx->f = format;

	va_start(ctx->l, format);
	_printf_runtime(ctx);
	va_end(ctx->l);

	return (context_consume(ctx));
}
