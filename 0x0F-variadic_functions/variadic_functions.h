#ifndef _VAR_FUNCS_
#define _VAR_FUNCS_
#include <stdarg.h>
/**
 * struct print_convert_variable - structure to hold function and char key
 * @type: abbreviation for type, i=int, c=char, f=float, s=string
 * @f: pointer to function for proper print statement
 *
 * Description: key:value, char:function, e.g: 'c':_print_char
 */
typedef struct print_convert_variable
{
	char type;
	void (*f)(va_list *);
} conv_t;
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *seperator, const unsigned int n, ...);
void print_strings(const char *seperator, const unsigned int n, ...);
void print_all(const char * const format, ...);
int _putchar(int);
#endif /* _VAR_FUNCS_ */
