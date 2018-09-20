#include "holberton.h"
/**
 * print_triangle - prints a triangle
 *
 * @size: sizexsize right triangle
 *
 * Return: always void
 */
void print_triangle(int size)
{
	int i, n, spaceC;

	i = 0;
	spaceC = size - 1;
	while (i < size)
	{
		n = 0;
		while (n < size)
		{
			if (n < spaceC)
				_putchar(' ');
			else
				_putchar('#');
			n++;
		}
		_putchar('\n');
		spaceC--;
		i++;
	}
	if (size < 1)
		_putchar('\n');
}
