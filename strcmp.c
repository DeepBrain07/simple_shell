#include "main.h"

/**
*_strcmp - compares two strings
*@s1: string 1
*@s2: string 2
*Return: 0 if they're equal or -1 if s1 < s2 and 1 if s1 > s2
*/
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 < *s2)
			return (-1);
		if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1)
		return (1);
	if (*s2)
		return (-1);
	return (0);
}
