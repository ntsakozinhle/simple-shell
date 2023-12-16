#include "main.h"

/**
 * _memcpy - copy memory from src to dest
 * @dest: destination memory area
 * @source: source memory area
 * @n: number of bytes
 */

void _memcpy(void *dest, const void *src, size_t n)
{
	char *d = (char *)dest;
	const char *s = (const char *)src;

	while (n--)
	{
		*d++ = *s++;
	}
}
