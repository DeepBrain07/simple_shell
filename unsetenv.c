#include "main.h"

/**
*unsetenv - unsets an environment variable
*@name: name of the variable
*Return: 0 on success, else failure
*/

extern char **environ;

int _unsetenv(const char *name)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		char *env_var = strdup(environ[i]);
		char *env_name = strtok(env_var, "=");
		if (env_name == NULL)
			continue;
		if (strcmp(env_name, name) == 0)
		{
			for (j = i; environ[j] != NULL; j++)
				environ[j] = environ[j + 1];
			environ[i] = NULL;
			return (0);
		}
	}

	return (-1);
}
