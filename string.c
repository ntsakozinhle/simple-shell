#include "main.h"

/**
 * _strncat - concatenates two strings
 * @dest: dest str
 * @src: source str
 * @n: max number of characters
 * Return: void
 */

void _strncat(char *dest, const char *src, size_t n)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
}

/**
 * _strlen - calculates length of string
 * @s: parameter for string
 * Return: length of string
 */

int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _strcmp - compares strings
 * @s1: first string to compare
 * @s2: secomd string to compare
 * Return: an integer greater/less than/ equal to length of s1
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strchr - locates first occurance of character in a string
 * @s: string
 * @c: char
 * Return: a pointer to first occurance
 */

const char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	if (*s == c)
	{
		return (s);
	}
	return (NULL);
}

/**
 * _strncmp - compares the first n characters of strings
 * @s1: first string
 * @s2: second string
 * @n: maximum number of characters to compare
 * Return: an integer greater than/ less than/ equal to s1
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		if (*s1 == '\0')
		{
			return (0);
		}

		s1++;
		s2++;
		n--;
	}
	return (0);
}
