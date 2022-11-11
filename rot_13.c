#include "main.h"
#include "typestr.h"
/**
 * rot13 - function
 * @str: char ptr
 *
 * Return: char ptr
 */
str		rot13(str s)
{
	i32	x;
	i32	y;
	str	a;
	str	b;

	a = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	b = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	for (x = 0; s[x]; x++)
	{
		for (y = 0; a[y]; y++)
		{
			if (a[y] == s[x])
			{
				s[x] = b[y];
				break;
			}
		}
	}
	return (s);
}
