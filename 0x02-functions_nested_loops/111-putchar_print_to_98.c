#include "holberton.h"
/**
 * print_to_98 - prints n..98
 *
 * @n: number to start at
 *
 * Return: always void
 */
void print_to_98(int n)
{
	int p1, p2, p3, tempN;

	while (n >= 98 || n < 98)
	{
		if (n < 0)
			_putchar('-');
		tempN = n;
		p3 = tempN % 10;
		tempN = tempN / 10;
		p2 = tempN % 10;
		tempN = tempN / 10;
		p1 = tempN % 10;
		if (n <= 0)
		{
			p1 = p1 * -1;
			p2 = p2 * -1;
			p3 = p3 * -1;
		}

		_putchar((p1 == 0) ? 0 : p1 + '0');
		_putchar((p1 == 0 && p2 == 0) ? 0 : p2 + '0');
		_putchar(p3 + '0');

		if (n == 98)
			break;
		_putchar(',');
		_putchar(' ');
		(n > 98) ? n-- : n++;
	}
	_putchar('\n');
}
