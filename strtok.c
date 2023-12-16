#include "main.h"

/**
 * print_tokens - a function that separates a string
 * @str1: parameter for string
 * @delim: parameter for strig separator
 * Return: separated string
 */

void print_tokens(char *str1, char *delim)
{
	char *str = _strdup(str1);
	char *token = strtok((char *)str, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	printf("Finished\n");

	free(str);
}
