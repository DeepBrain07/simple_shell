#include "main.h"

/**
*_strcpy - copies a string to a specified dest.
*@dst: destination
*@src: source
*Return: a pointer to the destination on success
*/

char *_strcpy(char *dst, const char *src)
{
	char *dst_ptr = dst;
	const char *src_ptr = src;
	while (*src_ptr)
		*dst_ptr++ = *src_ptr++;
	*dst_ptr = '\0';

	return (dst);
}
