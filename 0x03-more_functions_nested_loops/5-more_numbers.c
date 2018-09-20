#include "holberton.h"
/**
 * more_numbers - print 0..14 x 10
 *
 * Return: always void
 */
void more_numbers(void)
{
	int i, n;

	i = 0;
	while (i < 10)
	{
		n = 0;
		while (n <= 14)
		{
			if (n >= 10)
				_putchar((n / 10) + '0');
			_putchar((n % 10) + '0');
			n++;
		}
		_putchar('\n');
		i++;
	}
}
