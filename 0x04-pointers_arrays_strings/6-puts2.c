#include "holberton.h"
/**
 * puts2 - prints alternate characters
 *
 * @str: string to alternate print
 *
 * Return: always void
 */
void puts2(char *str)
{
	while (*str)
	{
		if (*str % 2 == 0)
			_putchar(*str);
		str++;
	}
	_putchar('\n');
}
