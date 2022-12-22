#include "main.h"

/**
*_putenv - adds an environment variable
*@string: variable to add to the environment
*Return: 0 on success, else failure
*/
extern char **environ;

int _putenv(char *string)
{
	char *existing;
	char *new_env_var;
	char *name = _strtok(string, "=");
	char *value = strtok(NULL, "=");

	if (name == NULL || value == NULL)
		return (-1);
	existing = _getenv(name);
	if (existing == NULL)
	{
		new_env_var = malloc(sizeof(char) * (_strlen(string) + 1));
		if (new_env_var == NULL)
			return (-1);
		_strcpy(new_env_var, string);
		environ = &new_env_var;
	}
	else
	{
		existing = _realloc(existing, strlen(string) + 1);
		if (existing == NULL)
			return (-1);
		_strcpy(existing, string);
	}

	return (0);
}
