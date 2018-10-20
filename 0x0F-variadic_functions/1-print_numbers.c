#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
#include <unistd.h>
void print_number(int n);
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

	va_start(nums, n);
	for (i = 0; i < n; i++) /* loop through variadic variables */
	{
		cur_num = va_arg(nums, int);
		print_number(cur_num);
		if (seperator == NULL || *seperator == '\0')
			continue;
		if (i != n - 1)
			printf("%s", seperator);
	}
	putchar('\n');
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
	printf("%d", n);
}
