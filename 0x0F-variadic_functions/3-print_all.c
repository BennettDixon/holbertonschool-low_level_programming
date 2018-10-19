#include <stdarg.h>
#include <stdio.h>
typedef struct print_convert_variable
{
	void (*f)(void *);
} conv_v;
void _print_char(void *ch);
void _print_integer(void *i);
void _print_float(void *f);
void _print_string(void *s);
/**
 * print_all - prints all parameters passed variadiclly
 * @format: string with types of variables, in order
 * @...: variables to print out
 *
 * Return: always void
 */
void print_all(const char * const format, ...)
{
	char *ch = "c";
	int i = 10;
	int *ip = &i;
	float f = 10.45;
	float *fp = &f;
	char *s = "test";

	/*    debug     */
	_print_char(ch);
	_print_integer(ip);
	_print_float(fp);
	_print_string(s);
	/* end of debug */

	putchar('\n');
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
