#include "holberton.h"
/**
 * print_diagonal - prints a diagonal line n long
 *
 * @n: length of line
 *
 * Return: always void
 */
void print_diagonal(int n)
{
	int i, spaceC;

	i = 0;
	while (n > 0 && i < n)
	{
		spaceC = 0;
		while (spaceC < i)
		{
			_putchar(' ');
			spaceC++;
		}
		_putchar('\\');
		_putchar('\n');
		i++;
	}
	if (n < 1)
		_putchar('\n');
}
