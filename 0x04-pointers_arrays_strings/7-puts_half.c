#include "holberton.h"
/**
 * puts_half - print second half of str
 *
 * @str: string to cut in half & print
 *
 * Return: always void
 */
void puts_half(char *str)
{
	int length, charsToPrint = 0;

	while (*(str + length) != '\0')
		length++;
	if (!(length % 2)) /* if uneven number */
		charsToPrint = (length - 1) / 2;
	else
		charsToPrint = length / 2;
	charsToPrint++;
	while (charsToPrint < length)
		_putchar(*(str + charsToPrint++));
	_putchar('\n');
}
