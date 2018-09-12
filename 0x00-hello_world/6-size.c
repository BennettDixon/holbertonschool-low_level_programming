#include <stdio.h>
/**
  * main - Entry point
  *
  * Description: prints sizes of different types in c
  *
  * Return: always 0 (success)
  */
int main(void)
{
	printf("Size of a char: %lu byte(s)\n", sizeof(char));
	printf("Size of an int: %lu byte(s)\n", sizeof(int));
	printf("Size of a long int: %lu byte(s)\n", sizeof(long));
	printf("Size of a long long int: %lu byte(s)\n", sizeof(double));
	printf("Size of a float: %lu byte(s)\n", sizeof(float));
	return (0);
}
