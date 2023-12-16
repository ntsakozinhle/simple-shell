#include "main.h"

/**
 * _getenv -  an environmental variable
 * @name: name of recalled variable
 * Return: value of the variable
 */

const char *_getenv(const char *name)
{
	char **env = environ;
	const char *value;

	if (name == NULL || environ == NULL)
	{
		return (NULL);
	}
	while (*env != NULL)
	{
		if (_strncmp(*env, name, _strlen(name)) == 0)
		{
			value = _strchr(*env, '=');
			if (value != NULL)
			{
				return (value + 1);
			}
		}
		env++;
	}
	return (NULL);
}

/**
 * print_env - print current environment varibales
 * Return: void
 */

void print_env(void)
{
	char **env = environ;

	if (environ == NULL)
	{
		return;
	}

	while (*env != NULL)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
