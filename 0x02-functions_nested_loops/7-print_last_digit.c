#include "holberton.h"
/**
 * print_last_digit - prints last digit
 *
 * @n: integer to get last digit from
 *
 * Return: the last digit
 */
int print_last_digit(int n)
{
	int r;

	r = n % 10;
	if (r < 0)
		_putchar(r * -1 + '0');
	else
		_putchar(r + '0');
	return (-1 * r);
}
