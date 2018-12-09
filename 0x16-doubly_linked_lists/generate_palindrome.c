#include <stdio.h>

/**
 * main - entry point to find palindrome program
 *
 * Return: always 0
 */
int main(void)
{
	unsigned int d1, d2, temp, max;

	max = 0;
	for (d1 = 100; d1 <= 999; d1++)
	{
		for (d2 = 100; d2 <= 999; d2++)
		{
			temp = d1 * d2;
			if (is_palindrome(temp))
				max = (temp > max) ? temp : max;
		}
	}
	printf("Largest palindrome of 3 digit numbers is: %d\n", max);
}

char is_palindrome(unsigned int n)
{
	unsigned int reverse;

	reverse = (n
}
