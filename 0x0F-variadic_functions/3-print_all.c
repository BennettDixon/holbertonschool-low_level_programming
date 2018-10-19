#include <stdarg.h>
#include <stdio.h>
typedef struct print_convert_variable
{
	char type;
	void (*f)(void *);
} conv_t;
void _print_char(void *ch);
void _print_integer(void *i);
void _print_float(void *f);
void _print_string(void *s);
void (*get_print_func(char ch))(void *);
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
	void *arg;
	void (*print_f)(void *);
	unsigned int i = 0;

	va_start(args, format);
	while ((*(format + i)))
	{
		arg = va_arg(args, void *);
		printf("char in loop:%c\n", *(format + i));
		print_f = get_print_func(*(format + i));
		if (print_f != NULL)
		{
			print_f(arg);
			printf(", ");
		}
		i++;
	}
	putchar('\n');
}
void (*get_print_func(char ch))(void *)
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
void _print_char(void *ch)
{
	printf("%c", *(char *)ch);
}
void _print_integer(void *i)
{
	printf("%d", *(int *)i);
}
void _print_float(void *f)
{
	printf("%f", *(float *)f);
}
void _print_string(void *s)
{
	char *str;

	str = s;
	if (str == NULL || *str == '\0')
		printf("(nil)");
	else
		printf("%s", str);
}
