#include "main.h"

/**
*start_process - executes commands
*@args: array of strings
*Return: 1 on success, else failure
*/
int start_process(char **args)
{
	pid_t pid;
	int i, j, status, cond;
	char *_path = malloc(sizeof(char) * 1024);

	if (_path == NULL)
	{
		write(2, "%s\n", "Unable to allocate space");
		exit(EXIT_FAILURE);
	}
	_path = _which(args[0]);
	pid = fork();
	if (pid == 0)
	{
		cond = execv(_path, args);
		if (cond == -1)
			perror("sh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("sh");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
