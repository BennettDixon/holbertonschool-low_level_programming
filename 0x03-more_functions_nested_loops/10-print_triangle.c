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

	if (size < 1)
	{
		_putchar('\n');
		return;
	}
	i = 0;
	spaceC = size - 1;
	while (i < size)
	{
		n = 0;
		while (n < size)
			_putchar((n++ < spaceC) ? ' ' : '#');
		_putchar('\n');
		spaceC--;
		i++;
	}
}
