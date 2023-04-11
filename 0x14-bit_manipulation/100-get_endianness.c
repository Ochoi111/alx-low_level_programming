#include <stdio.h>
#include "main.h"
/**
 * get_endianness - A function that Checks the endianness.
 *
 * Return: 0, if big endian.
 * If little endian return 1.
 */
int get_endianness(void)
{
	int value = 1;
	char *endian = (char *)&value;

	if (*endian == 1)
		return (1);

	return (0);
}
