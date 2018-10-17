#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"
/**
 * main - entry point for function
 * @argc: arg counter, number of args
 * @argv: array of pointers to args
 *
 * Description: calculates basic arithmetic
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char op;
	int (*op_func)(int, int);
	int result;

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}
	op = *(argv[2]);
	if ((op == '/' || op == '%') && !atoi(argv[3]))
	{ /* divide by zero exception */
		printf("Error\n");
		return (98);
	}

	/* actually do the operation now that we've error chcked */
	op_func = get_op_func(&op);
	if (op_func == NULL)
	{
		printf("Error\n");
		return (98);
	}
	result = op_func(atoi(argv[1]), atoi(argv[3]));
	printf("%d\n", result);
	return (0);
}
