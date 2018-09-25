#include "holberton.h"
/**
 * _puts - puts string to stdout
 *
 * @str: string to print to stdout
 *
 * Return: always void
 */
void _puts(char *str)
{
	int counter;

	counter = 0;
	while (*(str + counter) != '\0')
		_putchar(*(str + counter++));
	_putchar('\n');
}
