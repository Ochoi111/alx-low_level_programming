#include "main.h"
/**
 * times_table - Print the 9 times table
 *
 * Return: no return
 */

void times_table(void)
{
	int a, b, pd;

	for (a = 0; a <= 9; a++)
	{
		_putchar(48);
		for (b = 1; b <= 9; b++)
		{
			pd = a * b;
			_putchar(44);
			_putchar(32);
			if (pd <= 9)
			{
				_putchar(32);
			}
			else
			{
				_putchar((pd / 10) + 48);
				_putchar((pd % 10) + 48);
			}
		}
				_putchar('\n');
	}
}

