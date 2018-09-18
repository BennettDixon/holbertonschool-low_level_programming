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

	if (n < 0)
		n = (-(n));
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	r = n % 10;
	_putchar(r + '0');
	return (r);
}
