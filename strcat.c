#include "main.h"

/**
*_strcat - concatenates two srings
*@dest: string 1
*@src: string 2
*Return: pointer to the destination string
*/
char *_strcat(char *dest, const char *src)
{
	char *d = dest;

	while (*d)
		d++;
	while (*src++)
		*d++ = *src++;
	*d = '\0';

	return (dest);
}
