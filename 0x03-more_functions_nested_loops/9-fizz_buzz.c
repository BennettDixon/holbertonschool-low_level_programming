#include <stdio.h>
void fizz_buzz(void);
/**
 * main - entry point for function
 *
 * Return: always 0
 */
int main(void)
{
	fizz_buzz();
	return (0);
}

/**
 * fizz_buzz - print 0..99, more info in Desc
 *
 * Description: if multiple of 3 print fizz
 * if multiple of 5 print buzz, if both print FizzBuzz
 *
 * Return: always void
 */
void fizz_buzz(void)
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
			printf("FizzBuzz");
		else if (i % 3 == 0)
			printf("Fizz");
		else if (i % 5 == 0)
			printf("Buzz");
		else
			printf("%d", i);
		putchar(' ');
		i++;
	}
	putchar('\n');
}
