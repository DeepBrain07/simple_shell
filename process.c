#include "main.h"

/**
*start_process - executes commands
*@args: array of strings
*Return: 1 on success, else failure
*/

int start_process(char **args)
{
	pid_t pid;
	int  status, cond;

/*	if (_path == NULL)
	{
		write(2, "Unable to allocate space\n", 25);
		exit(EXIT_FAILURE);
	}*/
	pid = fork();
	if (pid == 0)
	{
		cond = execvp(args[0], args);
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
