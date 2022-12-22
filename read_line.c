#include "main.h"

/**
*read_line - reads a line from the shell
*Return: pointer to the line read
*/
char *read_line(void)
{
	int c, pos = 0, bufsize = 1024;
	char *buf;

	buf = malloc(sizeof(char) * bufsize);
	if (buf == NULL)
	{
		write(2, "Unable to allocate memory", 25);
		exit(EXIT_FAILURE);
	}
	c = getchar();
	buf[pos] = c;
	while (c != 10)
	{
		pos++;
		c = getchar();
		buf[pos] = c;
	}
	buf[pos] = '\0';

	return (buf);
}
