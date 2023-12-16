#include "main.h"

/**
 * make_fullpath - create file pathfor command
 * @cmd: command to execute
 * @pathcpy: copy of PATH
 * @fullpath: buffer to store full path
 * @fullpath_len: pointer to path length
 * Return: Always 0
 */

int make_fullpath(char *cmd, char *pathcpy, char *fullpath, int *fullpath_len)
{
	char *dir = strtok(pathcpy, ":");
	int dir_len, cmd_len;

	while (dir != NULL)
	{
		dir_len = _strlen(dir);
		cmd_len = _strlen(cmd);

		if (*fullpath_len + dir_len + cmd_len + 1 >= MAX_PATH_LENGTH)
		{
			perror("Error: Path length exceeded");
			return (-1);
		}

		_memcpy(fullpath + *fullpath_len, dir, dir_len);
		*fullpath_len += dir_len;

		fullpath[*fullpath_len] = '/';
		(*fullpath_len)++;

		_memcpy(fullpath + *fullpath_len, cmd, cmd_len);
		*fullpath_len += cmd_len;

		fullpath[*fullpath_len] = '\0';

		if (access(fullpath, X_OK) == 0)
		{
			return (0);
		}
		dir = strtok(NULL, ":");
		*fullpath_len = 0;
	}
	return (-1);
}

/**
 * existing_cmd - check if cmd exists
 * @cmd: command to check
 * Return: 1
 */

int existing_cmd(const char *cmd)
{
	const char *path_env = _getenv("PATH");
	char *path_env_copy;
	char *path;
	char fullpath[MAX_PATH_LENGTH];
	int path_len, cmd_len;

	if (path_env == NULL)
	{
		return (0);
	}
	path_env_copy = _strdup(path_env);
	if (path_env_copy == NULL)
	{
		perror("Error: stdrup");
		return (0);
	}

	path = strtok(path_env_copy, ":");
	while (path != NULL)
	{
		path_len = _strlen(path);
		cmd_len = _strlen(cmd);

		if (path_len + cmd_len + 2 < MAX_PATH_LENGTH)
		{
			fullpath[0] = '\0';
			_strncat(fullpath, path, path_len);
			_strncat(fullpath, "/", 1);
			_strncat(fullpath, cmd, cmd_len);

			if (access(fullpath, X_OK) == 0)
			{
				free(path_env_copy);
				return (1);
			}
		}
		path = strtok(NULL, ":");
	}
	free(path_env_copy);
	return (0);
}
