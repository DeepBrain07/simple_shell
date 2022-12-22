#include "main.h"

/**
*set_env - sets environment variable
*@args: arrayb of strings
*Return: 1 on success, else failure
*/
int set_env(char **args)
{
	int status;

	status = _setenv(args[1], args[2], 1);
	if (status != 0)
	{
		write(2, "Unable to set environment variable", 25);
		exit(EXIT_FAILURE);
	}

	return (1);
}
