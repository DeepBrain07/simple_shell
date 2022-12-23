#include "main.h"

/**
*_which - locates a command's path
*@command: the command
*Return: a pointer to the path of the command
*/
char *_which(const char *command)
{
	char path[] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"; // getenv("PATH");

	if (path == NULL)
		return (NULL);
	char *dir = _strtok(path, ":");

	while (dir != NULL)
	{
		char *full_path = malloc(sizeof(char) * (strlen(dir) + strlen(command) + 2));

	if (full_path == NULL)
		return (NULL);
	_strcpy(full_path, dir);
	_strcat(full_path, "/");
	_strcat(full_path, command);

	if (access(full_path, F_OK | X_OK) == 0)
		return (full_path);
	dir = _strtok(NULL, ":");
	}

	return (NULL);
} 
