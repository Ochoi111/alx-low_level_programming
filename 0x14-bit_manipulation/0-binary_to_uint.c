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

	if (!b)
		return (0);

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0);

		number <<= 1;
		if (*b == '1')
			number += 1;

		b++;
	}

	return (number);
}
