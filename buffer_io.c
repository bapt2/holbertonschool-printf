#include "main.h"

/**
 * buffer_flush - function
 * @buf: buffer_t ptr
 *
 * Return: buffer_t ptr
*/
buffer_t	*buffer_flush(buffer_t *buf)
{
	if (!buf)
		return (0);
	if (!buf->body)
		return (0);
	write(1, buf->body, buf->curr);
	free(buf->body);
	buf->body = (str) malloc_try(sizeof(u8) * 1024);
	buf->size = 1024;
	buf->curr = 0;
	return (buf);
}

/**
 * buffer_append_byte - function
 * @buf: buffer_t ptr
 * @v: u8
 *
 * Return: i32
*/
i32	buffer_append_byte(buffer_t *buf, u8 v)
{
	if (!buf)
		return (0);
	if (!buf->body)
		return (0);
	if (buf->curr >= buf->size)
		buffer_flush(buf);
	buf->body[buf->curr++] = v;
	return (1);
}

/**
 * buffer_append_bytes - function
 * @buf: buffer_t ptr
 * @src: void ptr
 * @size: i32
 *
 * Return: i32
*/
i32	buffer_append_bytes(buffer_t *buf, void *src, i32 size)
{
	i32	x;

	if (!buf)
		return (0);
	if (!buf->body)
		return (0);
	for (x = 0; x < size; x++)
		buffer_append_byte(buf, ((str) src)[x]);
	return (size);
}
