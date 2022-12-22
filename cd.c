#include "main.h"

/**
*cd - changes directory
*@args: array of strings
*Return: 1 on success, else 0
*/

int cd(char **args)
{
	int i, status, ret;
	char *oldpwd = _getenv("OLDPWD");
	char cwd[1024];

	if (args[1] == NULL)
	{
		getcwd(cwd, 1024);
		ret = _setenv("OLDPWD", cwd, 1);
		status = chdir(_getenv("HOME"));
	}
	else
	{
		if (_strcmp("-", args[1]) == 0 || _strcmp("$OLDPWD", args[1]) == 0)
		{
			if (oldpwd == NULL)
			{
				write(2, "%s", "OLDPWD not set\n");
				exit(EXIT_FAILURE);
			}
			status = chdir(oldpwd);
			write(1, "%s", oldpwd);
		}
		else if (_strcmp("~", args[1]) == 0 || _strcmp("$HOME", args[1]) == 0)
		}
			getcwd(cwd, 1024);
			ret = _setenv("OLDPWD", cwd, 1);
			status = chdir(_getenv("HOME"));
		}
		else
		{
			getcwd(cwd, 1024);
			ret = setenv("OLDPWD", cwd, 1);
			status = chdir(args[1]);
		}
	}
	if (status != 0)
		perror("sh");

	return (1);
}
