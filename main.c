#include "main.h"

/**
 * main - check code
 * @ac: parameter to be checked
 * @argv: argument vector
 * Return: always 0
 */

int main(int ac, char **argv)
{
	char *prompt = "shell ~$ ";
	char *lineptr;
	size_t n = 0;

	(void)ac;
	(void)argv;

	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s\n", lineptr);

	free(lineptr);
	return (0);
}
