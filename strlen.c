#include "main.h"

/**
*_strlen: calculates the length of a string
*@str: a string
*Return: the length of the string on success
*/
int _strlen(const char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}
