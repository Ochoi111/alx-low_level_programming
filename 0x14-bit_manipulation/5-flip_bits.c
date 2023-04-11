#include <stdio.h>
#include "main.h"
/**
 * flip_bits - A function that returns the number of bits
 * you would need to flip to get from one number to another.
 * @n: The first number
 * @m: The second number
 * Return: the number of bits you would need to flip to get from n to m
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_num = n ^ m;
	unsigned int len = 0;

	while (xor_num > 0)
	{
		if (xor_num & 1)
			len++;
		xor_num >>= 1;
	}

	return (len);
}
