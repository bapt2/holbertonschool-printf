#include "main.h"
#include "typestr.h"

/**
 * _strlen - gets length of string by iteration
 * @s: const char ptr
 *
 * Return: size_t
*/
size_t	_strlen(const char *s)
{
	size_t	x;

	if (!s)
		return (0);
	for (x = 0; s[x]; x++)
		;
	return (x);
}
