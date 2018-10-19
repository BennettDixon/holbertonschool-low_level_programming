#include <stdarg.h>
#include <unistd.h>
int _putchar(char c);
/**
 * print_strings - prints all strings given, variadic
 * @seperator: seperator to print between strings
 * @n: number of strings
 * @...: strings to print
 *
 * Return: always void
 */
void print_strings(const char *seperator, const unsigned int n, ...)
{
	va_list strs;
	unsigned int i;
	char *cur_str;
	const char *sep_cp;
	const char *nil, *nil_cp;

	nil = "(nil)";
	va_start(strs, n);

	for (i = 0; i < n; i++)
	{
		cur_str = va_arg(strs, char *);
		if (!*cur_str) /* null current string */
		{
			nil_cp = nil;
			while (*nil_cp)
				_putchar(*nil_cp++);
		}
		while (*cur_str) /* won't run if cur_str == NULL */
			_putchar(*cur_str++);
		sep_cp = seperator;
		while ((*sep_cp) && (i < (n - 1)))
			_putchar(*sep_cp++);
	}
	_putchar('\n');
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
