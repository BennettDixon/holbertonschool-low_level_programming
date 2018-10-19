#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
void _print_char(va_list *args);
void _print_integer(va_list *args);
void _print_float(va_list *args);
void _print_string(va_list *args);
void (*get_print_func(char ch))(va_list *args);
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
	void (*print_f)(va_list *);
	unsigned int i = 0;
	char *seperator = "";

	va_start(args, format);
	while ((*(format + i)))
	{
		print_f = get_print_func(*(format + i));
		if (print_f != NULL)
		{
			printf("%s", seperator);
			print_f(&args);
			seperator = ", ";
		}
		i++;
	}
	putchar('\n');
}
/**
 * get_print_func - gets proper print function for paramater in va_list
 * @ch: character to get proper function for
 *
 * Return: pointer to a function that returns void and takes a paramater of
 *	   type va_list
 */
void (*get_print_func(char ch))(va_list *)
{
	int i = 0;
	conv_t convs[] = {
		{ 'c', _print_char },
		{ 'i', _print_integer },
		{ 'f', _print_float },
		{ 's', _print_string },
		{ 0, NULL }
	};

	while (convs[i].f != NULL && convs[i].type != ch)
		i++;
	return (convs[i].f);
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
		printf("(nil)");
	else
		printf("%s", str);
}
