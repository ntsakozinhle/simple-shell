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
	char *lineptr = NULL, *lineptr_cpy = NULL;
	size_t n = 0;
	ssize_t nchars;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	(void)ac;

	while (1)
	{
		printf("%s", prompt);
		nchars = getline(&lineptr, &n, stdin);
		
		if (nchars == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}

		lineptr_cpy = malloc(sizeof(char) * nchars);
		if (lineptr_cpy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		strcpy(lineptr_cpy, lineptr);

		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		argv = malloc(sizeof(char *) * num_tokens);

		token = strtok(lineptr_cpy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		exec(argv);
	}

	free(lineptr_cpy);
	free(lineptr);

	return (0);
}
