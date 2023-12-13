#include "main.h"

/**
 * exec - a function that executes a command from PATH
 * @argv: argument vector
 * Return: void
 */

void exec(char **argv)
{
	char *command = NULL;
	char *actual_comm = NULL;

	if (argv)
	{
		command = argv[0];

		actual_comm = get_location(command);

		if (execve(actual_comm, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}

}
