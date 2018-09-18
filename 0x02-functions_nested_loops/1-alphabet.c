#include "holberton.h"
/**
 * print_alphabet - print alphabet out
 *
 * Return: void
 */
void print_alphabet(void)
{
	int ch = 'a';

	while (ch <= 'z')
	{
		_putchar(ch++);
	}
	_putchar('\n');
}
