#include "holberton.h"
/**
 * print_rev - prints str in reverse
 *
 * @s: string to print in reverse
 *
 * Return: always void
 */
void print_rev(char *s)
{
	int counter, strLength;

	counter = 0;
	while (*(s + counter) != '\0')
		counter++;
	strLength = counter;
	counter = 0;
	while (*(s + counter) != '\0')
		_putchar(*(s + (strLength - (counter++ + 1))));
	_putchar('\n');
}
