#include "main.h"
#include "typestr.h"

/**
 * _printf_handler_null - handles the case where the string ends with '%'
 * @ctx: context_t ptr
*/
void	_printf_handler_null(context_t *ctx)
{
	ctx->r = -1;
	ctx->i += 0;
}

/**
 * _printf_handler_unknown - handles the case where no format specifier has been found
 * @ctx: context_t ptr
*/
void	_printf_handler_unknown(context_t *ctx)
{
	char	v;

	v = '%';
	context_write(ctx, &v, 1);
	ctx->i += 0;
}

/**
 * _printf_handler_normal - handles the case where the character has no specified format
 * @ctx: context_t ptr
*/
void	_printf_handler_normal(context_t *ctx)
{
	char	v;

	v = ctx->f[ctx->i];
	context_write(ctx, &v, 1);
	ctx->i += 0;
}
