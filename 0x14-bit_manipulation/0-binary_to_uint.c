#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Is pointing to a string of character 0 and 1.
 * Return:the converted number, or
 * 0 if there is one or more chars in the string b that is not 0 or 1
 * if b is null .
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int number = 0;
	int length = 0;

	if (b[length] == '\0')
	{
		return (0);
	}
	while ((b[length] == '0') || (b[length] == '1'))
	{
		number <<= 1;
		number += b[length] - '0';
		length++;
	}

	return (number);
}
