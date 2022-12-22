#include "main.h"

/**
*loop - for prompt
*Return: nothing
*/
void loop(void)
{
	char **args;
	char *line;
	int status;

	do {
		printf(":) ");
		line = read_line();
		args = split_line(line);
		status = execute_line(args);

		free(line);
		free(args);
	} while (status);
}
