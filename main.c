#include "main.h"

/**
 * main - check the code
 * Return: Always 0
 */

int main(void)
{
	char *input = (char *)malloc(MAX_INPUT_SIZE);
	size_t input_size = MAX_INPUT_SIZE;
	ssize_t line_len;
	char *prompt = "~$ ";
	pid_t wpid;
	int wstat;

	if (input == NULL)
	{
		perror("Error: malloc");
		return (EXIT_FAILURE);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, prompt, 2);
		}

		line_len = getline(&input, &input_size, stdin);
		
		if (line_len == -1)
		{
			perror("Error: getline");
			free(input);
			exit(EXIT_FAILURE);
		}

		if (input[line_len - 1] == '\n')
			input[line_len - 1] = '\0';

		wpid = fork();
		if (wpid == -1)
		{
			perror("Error: fork");
			exit(EXIT_FAILURE);
		}
		if (wpid == 0)
			_exec(input);

		if (waitpid(wpid, &wstat, 0) == -1)
		{
			perror("Error: wait");
			exit(EXIT_FAILURE);
		}
	}
	free(input);
	return (0);
}
