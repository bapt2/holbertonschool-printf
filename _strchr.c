#include "main.h"
#include "typestr.h"

/**
 * _strchr - returns first occurance of v in s
 * @s: str
 * @v: char
 *
 * Return: str
*/
str	_strchr(str s, char v)
{
	i32	x;

	if (!s)
		return (0);
	for (x = 0; s[x]; x++)
		if (s[x] == v)
			return (&s[x]);
	return (0);
}
