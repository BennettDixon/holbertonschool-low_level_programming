#include <stdio.h>
/**
 * main - entry point for program
 *
 * @argC: count of args present
 * @argV: array of char * pointing to args
 *
 * Return: always 0 (success)
 */
int main(int argc, char *argv[])
{
	if (argc < 1)
		return (-1);
	printf("%s\n", argv[0]);
	return (0);
}
