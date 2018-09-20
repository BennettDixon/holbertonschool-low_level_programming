#include "holberton.h"
/**
 * print_line - prints a line n'_' long
 *
 * @n: number of times to print '_'
 *
 * Return: always void
 */
void print_line(int n)
{
	int i;

	i = 0;
	while (n > 0 && i < n)
	{
		_putchar('_');
		i++;
	}
	_putchar('\n');
}
