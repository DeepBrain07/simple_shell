#include "main.h"

/**
*start_process - executes commands
*@args: array of strings
*Return: 1 on success, else failure
*/
int start_process(char **args)
{
	pid_t pid;
	int  i, status, cond;
	char *_path = malloc(sizeof(char) * 1024);
	char *environ[3] = {"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin_=/usr/bin/env", "PWD=/root/simple_shell", "PWD=/root/simple_shell"};

	if (_path == NULL)
	{
		write(2, "Unable to allocate space\n", 25);
		exit(EXIT_FAILURE);
	}
	_path = _which(args[0]);

	pid = fork();
	if (pid == 0)
	{
//		_path = _which(args[0]);
		printf("%s\n", _path);
		cond = execve(_path, args, NULL);
		if (cond == -1)
		{
			//for (i = 0; environ[i]; i++)
			//	printf("%s\n", environ[0]);
			//perror("sh");
			printf("%s\n", _which(args[0]));
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("sh");
	else
	{/*
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status)); */
		waitpid(pid, &status, 0);
	}

	return (1);
}
