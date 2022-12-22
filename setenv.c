#include "main.h"
/**
*_setenv - sets an environment variable
*@name: name of the variable
*@value: value of the variable
*@overwrite: if to overwrite the variable or not
*Return: return value of _putenv, else failure
*/
int _setenv(const char *name, const char *value, int overwrite)
{
	int size, result;
	char var;

	if (!overwrite && getenv(name))
		return (0);
	size = _strlen(name) + 1 + _strlen(value) + 1;
	var = malloc(sizeof(char) * size);
	if (!var)
		return (-1);
	_strcpy(var, name);
	_strcat(var, "=");
	_strcat(var, value);
	result = _putenv(var);
	if (result != 0)
		free(var);

	return (result);
}
