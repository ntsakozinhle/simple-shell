#include "main.h"

/**
 * remove_str - removes everything after #
 * @input: parameter for char inputed
 * Return: void
 */

void remove_str(char *input)
{
	int i = 0;

	while (input[i] != '\0')
	{
		if (input[i] == '#' && (i == 0 || isspace(input[i - 1])))
		{
			input[i] = '\0';
			break;
		}
		i++;
	}
}
