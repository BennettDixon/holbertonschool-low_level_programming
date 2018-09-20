#include "holberton.h"
/**
 * print_numbers - print numbers 0..9\n
 *
 * Return: always void
 */
void print_numbers(void)
{
	int i = 48; /* ascii: 0 */

	while (i <= 57) /* ascii: 9 */
	{
		_putchar(i++);
	}
	_putchar('\n');
}
