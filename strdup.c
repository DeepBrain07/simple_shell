#include "main.h"

/**
*_strdup - duplicates a string
*@src: a string
*Return: a pointer to the destinstion
*/
char *_strdup(const char *src)
{
	int len = _strlen(src) + 1;
	char *dest = malloc(sizeof(char) * len);

	if (dest == NULL)
		return (NULL);
	_strcpy(dest, src);

	return (dest);
}
