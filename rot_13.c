#include "main.h"
#include "typestr.h"

/**
 * rot13 - applies rot13 to string
 * @s: str
 *
 * Return: str
 */
str	rot13(str s)
{
	str	d;
	i32	x;

	d = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	if (!s)
		return (0);
	for (x = 0; s[x]; x++)
		if (_strchr(d, s[x]))
			s[x] = d[((_strchr(d, s[x]) - d) >= 26) * 26 + ((
				_strchr(d, s[x]) - d) + 13) % 26];
	return (s);
}
