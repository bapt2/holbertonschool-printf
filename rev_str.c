#include "main.h"

/**
 * _printf_handler_reversed_string
 * @ctx: context_t ptr
*/
void            _printf_handler_reversed_string(context_t *ctx)
{
	char	*v;
	int	 x;

	v = (char *) va_arg(ctx->l, char *);
	if (!v)
	{
		v = ")null(";

		context_write(ctx, v, _strlen(v));
	}
	else
	{
		for (x = 0; v[x]; x++)
	       		;
		x--;
		for (; x >= 0; x--)	
			context_write(ctx, v, _strlen(v));
	}	
	ctx->i -= 1;
}
