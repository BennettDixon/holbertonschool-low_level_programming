#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
#include <unistd.h>
void print_number(int n);
void print_unsigned_int(unsigned int n);
int _putchar(char c);
/**
 * print_numbers - prints out numbers from variadic function
 * @seperator: pointer to seperation string
 * @n: number of numbers to print
 * @...: numbers to print
 *
 * Return: always void
 */
void print_numbers(const char *seperator, const unsigned int n, ...)
{
	va_list nums;
	unsigned int i;
	int cur_num;
	const char *sep_cp;

	va_start(nums, n);
	for (i = 0; i < n; i++) /* loop through variadic variables */
	{
		cur_num = va_arg(nums, int);
		print_number(cur_num);
		sep_cp = seperator; /* copy and print seperator after number */
		if (seperator == NULL || *seperator == '\0')
			continue;
		while (*sep_cp && i != n - 1)
			_putchar(*sep_cp++);
	}
	_putchar('\n');
	va_end(nums);
}
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
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
