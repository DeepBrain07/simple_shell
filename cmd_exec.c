#include "main.h"

/**
*start_process - executes commands
*@args: array of strings
*Return: 1 on success, else failure
*/
int cmd_exec(char **args)
{
	pid_t pid;
	int  i, status, cond, status2 = 0;
	char *_path = malloc(sizeof(char) * 1024);

	if (_path == NULL)
	{
		write(2, "Unable to allocate space\n", 25);
		exit(EXIT_FAILURE);
	}
	_path = _which(args[0]);

	pid = fork();
	if (pid == 0)
	{
		for (i = 0; args[0][i]; i++)
			if (args[0][i] == '/')
			{
				status2++;
				cond = execve(args[0], args, NULL);
				break;
			}
		if (status2 == 0)
			cond = execve(_path, args, NULL);
		if (cond == -1)
			perror("sh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("sh");
	else
	{
		waitpid(pid, &status, 0);
	}

	return (1);
}
