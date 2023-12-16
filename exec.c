#include "main.h"

/**
 * _exec - a program that executes other files
 * @input: parameter for vaiable input
 * Return: void
 */

void _exec(char *input)
{
	char *cmd = strtok(input, " ");
	pid_t child_pid;

	if (cmd == NULL)
	{
		return;
	}

	remove_str(input);

	if (_strcmp(cmd, "exit") == 0)
	{
		free(input);
		exit(0);
	}

	else if (_strcmp(cmd, "env") == 0)
	{
		print_env();
		return;
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: fork");
		exit(2);
	}

	if (child_pid == 0)
	{
		_exec_args(cmd);
		exit(127);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * _exec_args - a function that executes command with arguments
 * @cmd: command to execute
 * Return: void
 */

void _exec_args(char *cmd)
{
	char **argv = (char **) malloc(sizeof(char *) * MAX_ARG_COUNT);
	char *pathcpy;
	char fullpath[MAX_PATH_LENGTH];
	int fullpath_len = 0;

	arg_array(cmd, argv);

	if (_strchr(cmd, '/') != NULL)
	{
		_exec_cmd(cmd, argv);
	}
	else
	{
		const char *path = _getenv("PATH");

		if (path == NULL)
		{
			perror("getenv");
			exit(EXIT_FAILURE);
		}

		pathcpy = _strdup(path);
		if (pathcpy == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}

		if (make_fullpath(cmd, pathcpy, fullpath, &fullpath_len) == 0)
		{
			_exec_cmd(fullpath, argv);
		}
		else
		{
			child_exit(argv);
			free(pathcpy);
		}
		free(argv);
	}
}

/**
 * child_exit - chiild exit status
 * @argv: argument vector
 * Return: void
 */

void child_exit(char **argv)
{
	int status;
	
	wait(&status);

	if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
	{
		perror(argv[0]);
		exit(127);
	}
}

/**
 * arg_array - arg array for cmd
 * @cmd: command used for execution
 * @argv: argument vector
 * Return: number of arguments
 */

int arg_array(char *cmd, char **argv)
{
	int count = 0;
	char *arg;

	argv[count++] = cmd;
	arg = strtok(NULL, " ");

	while (arg != NULL && count < (MAX_ARG_COUNT - 1))
	{
		argv[count++] = arg;
		arg = strtok(NULL, " ");
	}

	argv[count] = NULL;
	return (count);
}

/**
 * _exec_cmd - execute command with arguments
 * @fullpath: full path to command
 * @argv: argument vector
 * Return: void
 */

void _exec_cmd(char *fullpath, char **argv)
{
	if (execve(fullpath, argv, environ) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
