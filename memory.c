#include "main.h"

/**
 * malloc_try - function
 * @size: size_t
 *
 * Return: void ptr
*/
void	*malloc_try(size_t size)
{
	void	*r;

	r = malloc(size);
	if (!r)
	{
		exit(1);
	}
	return (r);
}
