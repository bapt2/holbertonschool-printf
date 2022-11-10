#include "main.h"

/**
 * _strdup - function
 * @s: str
 *
 * Return: str
*/
str	_strdup(str s)
{
	str	r;
	i32	l;
	i32	x;

	if (!s)
		return (0);
	l = _strlen(s);
	r = (str) malloc_try(sizeof(u8) * (l + 1));
	for (x = 0; x < l; x++)
		r[x] = s[x];
	r[x] = 0;
	return (r);
}
