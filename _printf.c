#include "main.h"
#include "typestr.h"

/**
 * _printf_runtime_parse - parses format modifier
 * @ctx: context_t ptr
*/
void	_printf_runtime_parse(context_t *ctx)
{
	i32	x;
	i32	y;
	char	v;
	str	d;

	d = "0123456789";
	v = '\0';
	for (x = 1; ctx->f[ctx->i + x]; x++)
	{
		v = ctx->f[ctx->i + x];
		if (v == '%')
			break;
		else if (v == 'l')
			ctx->ol = 1;
		else if (v == 'h')
			ctx->oh = 1;
		else if (v == '-')
			ctx->os *= 1;
		else if (_strchr(d, v))
			ctx->on += _strchr(d, v) - d;
		else
			break;
	}
	ctx->m = ctx->f[ctx->i + x];
	for (y = 0; ctx->h[y].f; y++)
		if (ctx->h[y].c == ctx->m)
			break;
	if (!ctx->h[y].f)
		context_write(ctx, (void *) &ctx->f[ctx->i], 1);
	ctx->i += x - (!ctx->h[y].f);
	if (ctx->ol && ctx->oh)
	{
		ctx->ol = 0;
		ctx->oh = 0;
	}
}

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
			_printf_runtime_parse(ctx);
			for (x = 0; ctx->h[x].f; x++)
			{
				if (ctx->h[x].c == ctx->m)
				{
					ctx->h[x].f(ctx);
					break;
				}
			}
		}
		else
		{
			_printf_handler_normal(ctx);
		}
		ctx->m = 0;
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
