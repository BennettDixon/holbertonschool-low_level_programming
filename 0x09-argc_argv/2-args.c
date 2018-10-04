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
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
