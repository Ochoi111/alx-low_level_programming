#include <stdio.h>
#include "main.h"
/**
 * get_bit - get the value of  bit at a given index
 * @n: get the bit
 * @index: is the index, starting from 0
 * of the bit you want to get
 *
 * Return: value of the bit at index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);
	return ((n >> index) & 1);
}
