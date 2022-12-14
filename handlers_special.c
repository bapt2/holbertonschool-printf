#include "main.h"
#include "typestr.h"

/**
 * _printf_handler_null - handles the case where the string ends with '%'
 * @ctx: context_t ptr
*/
void	_printf_handler_null(context_t *ctx)
{
	ctx->r = -1;
}

/**
 * _printf_handler_unknown - handles the case where no format's found
 * @ctx: context_t ptr
*/
void	_printf_handler_unknown(context_t *ctx)
{
	char	v;

	v = '%';
	context_write(ctx, &v, 1);
}

/**
 * _printf_handler_normal - handles the case where printing is normal
 * @ctx: context_t ptr
*/
void	_printf_handler_normal(context_t *ctx)
{
	char	v;

	v = ctx->f[ctx->i];
	context_write(ctx, &v, 1);
}

/**
 * _printf_handler_string_rot13 - handles rot13 applied strings
 * @ctx: context_t ptr
*/
void    _printf_handler_string_rot13(context_t *ctx)
{
	char	*v;

	v = (char *) va_arg(ctx->l, char *);
	if (!v)
	{
		v = _strdup("(null)");
	}
	else
		v = rot13(_strdup(v));
	context_write(ctx, v, _strlen(v));
	free(v);
}
