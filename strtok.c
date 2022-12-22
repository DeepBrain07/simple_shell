#include "main.h"

/**
*_strtok - tokennizes a string
*@str: string to tokenize
*@delim: delimeter
*Return: pointer to the tokenized string on success
*/
char *_strtok(char *str, const char *delim)
{
	char *start;
	static char *curr = NULL;

	if (str != NULL)
		curr = str;
	if (curr == NULL || *curr == '\0')
		return (NULL);
	start = curr;
	while (*curr != '\0' && strchr(delim, *curr) == NULL)
		curr++;
	if (*curr != '\0')
		*curr++ = '\0';

	return (start);
}
