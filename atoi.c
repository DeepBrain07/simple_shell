#include "main.h"

/**
*_atoi - converts a string to decimal
*@str: string to be converted
*Return: the result of the conversion
*/
int atoi(const char *str)
{
	int result = 0, sign = 1;

	while (isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	return (sign + result);
}
