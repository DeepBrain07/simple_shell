#include "main.h"

/**
*or_sh - handles the '||' sign
*@args: array of strings
*Return: 1 on success, esle failure
*/
int or_sh(char **args)
{
	char **buf = malloc(sizeof(char *) * 64);
	char _path[1024] = {'/', 'b', 'i', 'n', '/'};
	int i, j, k = 5, position = 0;

	for (i = 0; args[i]; i++)
	{
		if (_strcmp(args[i], "||") == 0)
		{
			buf[position] = NULL;
			start_process(buf);
			for (j = 0; buf[0][j]; j++)
			{
				_path[k] = buf[0][j];
				k++;
			}
			if (access(_path, F_OK) == 0)
				return (1);
			k = 5;
			position = 0;
		}
		else
		{
			buf[position] = args[i];
			position++;
		}
	}
	buf[position] = NULL;
	start_process(buf);

	return (1);
}
