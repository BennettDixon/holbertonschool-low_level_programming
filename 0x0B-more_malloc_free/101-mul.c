#include <stdio.h>
int contains_non_numeric(char *str);
int _atoi(char *s);
/**
 * main - entry point for program
 *
 * @argc: count of arguments
 * @argv: list of pointers to arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	int i, n[2], resSize = 0;
	char *ret;

	if (argc != 3)
	{	
		printf("Error\n");
		return (98);
	}
	for (i = 1; i < argc; i++)
	{
		if (contains_non_numeric(argv[i]))
		{
			printf("Error\n");
			return (98);
		}
	}
	resSize =
	multiply_strings
	printf("%d\n", n[0] * n[1]);
	return (0);
}
/**
 * contains_non_numeric - checks if string has non numeric values
 *
 * @str: string to check
 *
 * Return: 1 if contains non numeric values, 0 if only numeric
 */
int contains_non_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}
/**
 * _atoi - converts string to integer
 *
 * @s: string to convert from
 *
 * Return: integer from conversion, -1 if contains nonint
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char working = 0;

	while (*s)
	{
		if (*s == '-')
			sign = sign * -1;
		if (*s >= '0' && *s <= '9')
		{
			working = 1;
			total = total * 10 + *s - '0';
		}
		else if (*s < '0' || *s > '9')
		{
			if (working)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-(total));
	return (total);
}
