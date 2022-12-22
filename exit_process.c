#include "main.h"

/**
*exit_process - exits the current process
*@args: array of strings
*Return: returns the status on success, else failure
*/
int exit_process(char **args)
{
	int status;

	if (args[1])
		status = _atoi(args[1]);
	else
		status = 0;
	_exit(status - 1);
}
