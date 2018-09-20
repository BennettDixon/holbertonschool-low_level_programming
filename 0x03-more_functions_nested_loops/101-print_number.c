#include "holberton.h"
void print_unsigned_int(unsigned int n);
/**
 * print_number - print number n with putchar
 *
 * @n: number to print
 *
 * Return: always void
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		print_unsigned_int(-(unsigned int)n);
	}
	else
		print_unsigned_int(n);
}
/**
 * print_unsigned_int - prints an unsigned integer
 *
 * @n: an unsigned integer to print
 *
 * Return: always void
 */
void print_unsigned_int(unsigned int n)
{
	if (n / 10 != 0)
	{
		print_unsigned_int(n / 10);
	}
	_putchar((n % 10) + '0');
}
