#include "main.h"

/**
 * _strdup - duplicates string
 * @s: parameter for string
 * Return: a pointer containing duplicated string
 */

char *_strdup(const char *s)
{
	size_t len = _strlen(s) + 1;
	char *dup = (char *)malloc(len);

	if (dup == NULL)
	{
		perror("Error: malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(dup, s);
	return (dup);
}

/**
 * _strcpy - a function that copies a string
 * @dest: destination str
 * @src: source str
 * Return: pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
