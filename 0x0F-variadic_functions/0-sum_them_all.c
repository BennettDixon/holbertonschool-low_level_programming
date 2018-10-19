#include <stdarg.h>
#include <stdio.h>
/**
 * sum_them_all - sums all integers given, variadic function
 * @n: number of arguments
 * @...: rest of arguments, presumed to be integers
 *
 * Return: sum of rest of arguments
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int sum = 0;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return (sum);
}
