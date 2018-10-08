#include <stdio.h>
#include <stdlib.h>
int get_change(int amount);
/**
 * main - entry point for change program
 *
 * @argc: arg counter, # of args passed
 * @argv: array of args passed
 *
 * Return: 0 for success, 1 for error
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	printf("%d\n", get_change(atoi(argv[1])));
	return (0);
}
/**
 * get_change - gets smallest amount of coins needed
 *
 * @amount: amount to find num coins needed for
 *
 * Return: number of coins needed to make change
 */
int get_change(int amount)
{
	/* qs: quarters, ds: dimes, ns: nickles */
	/* tcs: two cents, ocs: one cents */
	int qs, ds, ns, tcs, ocs;

	qs = 0, ds = 0, ns = 0, tcs = 0, ocs = 0;
	if (amount <= 0)
		return (0);
	while (amount >= 25)
	{
		amount -= 25;
		qs++;
	}
	while (amount >= 10)
	{
		amount -= 10;
		ds++;
	}
	while (amount >= 5)
	{
		amount -= 5;
		ns++;
	}
	while (amount >= 2)
	{
		amount -= 2;
		tcs++;
	}
	while (amount >= 1)
	{
		amount -= 1;
		ocs++;
	}
	return (qs + ds + ns + tcs + ocs);
}
