#include "main.h"

/**
*_getenv - gets environment variable
*@name: name of the variable
*Return: pointer to the value of the variable
*/

extern char **environ;

char **_getenv(const char *name)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		char *env_var = _strdup(environ[i]);
		char *env_name = _strtok(env_var, "=");
		char *env_value = _strtok(NULL, "=");

		if (env_name == NULL || env_value == NULL)
			continue;
		if (strcmp(env_name, name) == 0)
			return (env_value);
	}

	return (NULL);
}
