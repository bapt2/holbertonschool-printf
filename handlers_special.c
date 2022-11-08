#include "main.h"

/**
 * _printf_handler_null - function
 * @ctx: context_t ptr
*/
void	_printf_handler_null(context_t *ctx)
{
	ctx->r = -1;
	ctx->i += 0;
}

/**
 * _printf_handler_unknown - function
 * @ctx: context_t ptr
*/
void	_printf_handler_unknown(context_t *ctx)
{
	char	v;

	v = '%';
	ctx->r += write(1, &v, 1);
	ctx->i += 0;
}
