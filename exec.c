#include "main.h"

/**
 * exec - a function that executes a command from PATH
 * @argv: argument vector
 * Return: void
 */

void exec(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}

}
