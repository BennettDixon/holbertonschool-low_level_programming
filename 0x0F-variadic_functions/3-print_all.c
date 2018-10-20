#include <stdio.h>
#include "variadic_functions.h"
void _print_char(va_list *args);
void _print_integer(va_list *args);
void _print_float(va_list *args);
void _print_string(va_list *args);
/**
 * print_all - prints all parameters passed variadiclly
 * @format: string with types of variables, in order
 * @...: variables to print out
 *
 * Return: always void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	int n = 0;
	char *seperator = "";
	conv_t convs[] = {
		{ 'c', _print_char },
		{ 'i', _print_integer },
		{ 'f', _print_float },
		{ 's', _print_string },
		{ 0, NULL }
	};

	va_start(args, format);
	while (format && (*(format + i)))
	{
		n = 0;
		while (convs[n].f != NULL && convs[n].type != *(format + i))
			n++;
		if (convs[n].f != NULL)
		{
			printf("%s", seperator);
			convs[n].f(&args);
			seperator = ", ";
		}
		i++;
	}
	va_end(args);
	putchar('\n');
}
/**
 * _print_char - prints a character
 * @args: va_list to get character from, presumed to be type of arg
 *
 * Return: always void
 */
void _print_char(va_list *args)
{
	char ch;

	ch = va_arg(*args, int);
	printf("%c", ch);
}
/**
 * _print_integer - prints an integer
 * @args: va_list to get integer from, presumed to be type of arg
 *
 * Return: always void
 */
void _print_integer(va_list *args)
{
	int i;

	i = va_arg(*args, int);
	printf("%d", i);
}
/**
 * _print_float - prints a float
 * @args: va_list to get float from, presumed to be type of arg
 *
 * Return: always void
 */
void _print_float(va_list *args)
{
	float f;

	f = va_arg(*args, double);
	printf("%f", f);
}
/**
 * _print_string - prints a string
 * @args: va_list to get char * from, presumed to be type of arg
 *
 * Return: always void
 */
void _print_string(va_list *args)
{
	char *str;

	str = va_arg(*args, char *);
	if (str == NULL || *str == '\0')
		str = "(nil)";
	printf("%s", str);
}
