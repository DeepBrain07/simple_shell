#include "main.h"
/**
*var_rep - variable representative
*args: array of strings
*Return: 1 on success, else failure
*/
int var_rep(char **args)
{
	int i;
	char buf[1024], buf2[1024];
	char *buf3 = malloc(sizeof(char) * 1024);
	char **token = malloc(sizeof(char *) * 64);
	pid_t mypid;

	if (buf3 == NULL || token == NULL)
	{
		write(2, "%s", "Unable to allocate space\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; args[i]; i++)
	{
		if (args[i][0] == '$' && args[i][1] == '$' && !args[i][2])
		{
			mypid = getppid();
			printf("%u\n", mypid);
			return (1);
		}
		else if (args[i][0] == '$')
			_strcpy(buf, args[i]);
	}
	for (i = 1; buf[i]; i++)
		buf2[i - 1] = buf[i];
	buf3 = _getenv(buf2);
	if (buf3)
	{
		for (i = 0; args[i]; i++)
		{
			if (strcmp(args[i], buf) == 0)
				token[i] = buf3;
			else
				token[i] = args[i];
		}
		free(buf3);
		return (start_process(token));
	}
	return (1);
}
