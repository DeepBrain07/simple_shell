#include "main.h"
#define DELIMS " \t\r\n\a"

/**
*split_line - splits the line read from the shell
*@str: line read from the shell
*Return: pointer to the splitted line
*/
char **split_line(char *str)
{
	int position = 0, bufsize = 64;
	char *token;
	char **myStr = malloc(sizeof(char *) * bufsize);

	if (myStr == NULL)
	{
		write(2, "%s\n", "Unable to allocate space");
		exit(EXIT_FAILURE);
	}
	token = _strtok(str, DELIMS);
	while (token)
	{
		myStr[position] = token;
		position++;
		token = _strtok(NULL, DELIMS);
	}
	myStr[position] = NULL;

	return (myStr);
}
