#include "main.h"
#include "typestr.h"

/**
 * _strrev - function
 * @s: str
 *
 * Return: str
*/
str	_strrev(str s)
{
	i32	l;
	i32	x;
	u8	v;

	if (!s)
		return (0);
	l = _strlen(s);
	for (x = 0; x < l / 2; x++)
	{
		v = s[x];
		s[x] = s[l - 1 - x];
		s[l - 1 - x] = v;
	}
	return (s);
}
