#include "main.h"

/**
*unset_env - unsets an environment
*@args: array of strings
*Return: 1 on success, else failure
*/
int unset_env(char **args)
{
	int status;

	status = _unsetenv(args[1]);
	if (status != 0)
	{
		write(2, "%s\n", "Unable to unset environment variable\n");
		exit(EXIT_FAILURE);
	{

	return (1);
}
