#include "main.h"
#include "typestr.h"

/**
 * malloc_try - allocates memory that is filled with 0 while exiting the program on failure
 * @size: size_t
 *
 * Return: void ptr
*/
void	*malloc_try(size_t size)
{
	void	*r;
	size_t	x;

	r = malloc(size);
	if (!r)
	{
		exit(1);
	}
	for (x = 0; x < size; x++)
		((u8 *) r)[x] = 0;
	return (r);
}
