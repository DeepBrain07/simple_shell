#include "main.h"

/**
*_strcat - concatenates two srings
*@dest: string 1
*@src: string 2
*Return: pointer to the destination string
*/
char *_strcat(char *dest, const char *src)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; src[i]; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
