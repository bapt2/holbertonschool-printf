#include "main.h"

/**
 * buffer_new - function
 * @buf: buffer_t ptr
 *
 * Return: buffer_t ptr
*/
buffer_t	*buffer_new(buffer_t *buf)
{
	if (buf)
		buffer_free(buf);
	buf = (buffer_t *) malloc_try(sizeof(buffer_t));
	buf->body = (str) malloc_try(sizeof(u8) * 1024);
	buf->size = 1024;
	buf->curr = 0;
	return (buf);
}

/**
 * buffer_free - function
 * @buf: buffer_t ptr
 *
 * Return: buffer_t ptr
*/
buffer_t	*buffer_free(buffer_t *buf)
{
	if (!buf)
		return (0);

	if (buf->body)
		free(buf->body);

	free(buf);
	return (0);
}
