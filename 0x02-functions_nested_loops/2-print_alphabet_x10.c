#include "main.h"
/**
 * print_alphabet_x10 - print 10 times the alphabet in lowercase
 * followed by a new line
 */
void print_alphabet_x10(void)
{
	char rep;
	int i = 0;

	while (i < 10)
	{
		rep = 'a';
		while (rep <= 'z')
		{
			_putchar(rep);
			rep++;
		}
		_putchar('\n');
		i++;
	}
}

