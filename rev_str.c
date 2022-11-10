#include "main.h"

/**
 * _printf_handler_reversed_string
 * @ctx: context_t ptr
*/
void            _printf_handler_reversed_string(context_t *ctx)
{
	char	*v;

	{
	v = (char *) va_arg(ctx->l, char *);
	if (!v)
		v = ")null(";

	context_write(ctx, v, _strlen(v));
	ctx->i -= 1;
	}
_printf("%r", v);
printf("%r", v);
}
