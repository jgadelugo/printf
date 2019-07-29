#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * _memcpy - copies memory area
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy
 * @bufferlen: current number of bytes taken by buffer
 * Return: pointer to destination memory area
 */

char *_memcpy(char *dest, char *src, unsigned int n, unsigned int bufferlen)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i + bufferlen] = src[i];
	return (dest);
}

/**
 * alloc_buffer - allocates characters to buffer, with overflows
 * @hold: string to allocate into buffer
 * @hlen: hold length
 * @buffer: buffer char array
 * @bufend: end of buffer
 * @total: pointer to total character counter
 * Return: buffer length
 */

int alloc_buffer(char *hold, int hlen, char *buffer, int bufend, double *total)
{
	int sizecpy = 0;

	if (hlen + bufend > BUFSIZE)
	{
		sizecpy = BUFSIZE - bufend;
		_memcpy(buffer, hold, sizecpy, bufend);
		_puts(buffer, BUFSIZE);
		hold += sizecpy;
		_memcpy(buffer, hold, hlen - sizecpy, 0);
		bufend = hlen - sizecpy;
		*total += BUFSIZE;
	}
	else
	{
		_memcpy(buffer, hold, hlen, bufend);
		bufend += hlen;
	}
	return (bufend);
}
