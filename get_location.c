#include "main.h"
/**
 * get_location - a fncation the inputs the PATH of a file to execute
 * @command: name of executable file
 * Return: executed file
 */
char *get_location(char *command)
{
	char *path, *path_cpy, *path_token, *file_path;
	int comm_len, direc_len;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_cpy = strdup(path);
		comm_len = strlen(command);
		path_token = strtok(path_cpy, ":");
		while (path_token != NULL)
		{
			direc_len = strlen(path_token);
			file_path = malloc(comm_len + direc_len + 2);

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
