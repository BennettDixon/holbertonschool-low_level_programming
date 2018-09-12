#include <stdio.h>
/**
 * main - Entry point for function
 *
 * Description: Outputs our quote to stderr
 * instead of stdout
 *
 * Return: 1 always (success)
 */
int main(void)
{
	char *quote = "and that piece of art is useful\" -Dora Korpar, 2015-10-19";

	fprintf(stderr, "%s\n", quote);
	return (1);
}
