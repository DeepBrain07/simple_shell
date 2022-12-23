#include "main.h"

void write_int(int num)
{
	char c;

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	do {
		c = num % 10 + '0';
		write(1, &c, 1);
		num /= 10;
	} while (num > 0);
}
