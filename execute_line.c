#include "main.h"

/**
*execute_line - executes commands
*@args: array of strings
*Return: 1 on success, else failure
*num_of_builtins returns the number of builtin functions on success
*/
int execute_line(char **args)
{
	int i;
	char *builtins[] = {"cd", "exit"};

	int (*builtin_func[]) (char **) = {&cd, &exit_process};

	int num_of_builtins(void)
	{
		return (sizeof(builtins) / sizeof(char *));
	}

	if (args[0] == NULL)
		return (1);
	for (i = 0; args[i]; i++)
	{
		if (_strcmp(args[i], "setenv") == 0)
			return (set_env(args));
		else if (_strcmp(args[0], "unsetenv") == 0)
			return (unset_env(args));
		else if (args[i][0] == '$')
			return (var_rep(args));
		else if (i != 0 && _strcmp(args[i], "&&") == 0)
			return (and_sh(args));
		else if (i != 0 && _strcmp(args[i], "||") == 0)
			return (or_sh(args));
	}
	for (i = 0; i < num_of_builtins(); i++)
		if (_strcmp(args[0], builtins[i]) == 0)
			return ((*builtin_func[i])(args));
	return (start_process(args));
}
