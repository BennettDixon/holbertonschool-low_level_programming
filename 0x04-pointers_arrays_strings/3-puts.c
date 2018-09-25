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
	while (*str)
		_putchar(*str++);
	_putchar('\n');
}
