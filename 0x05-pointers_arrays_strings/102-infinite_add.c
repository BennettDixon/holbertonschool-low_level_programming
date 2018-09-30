#include <stdio.h> /* debugging use */
#define FILL 100 /* fill with 'd' */
/**
 * infinite_add - adds two numbers
 *
 * @n1: *char - first number
 * @n2: *char - second number
 * @r:  *char - buffer where result is stored
 * @size_r: int - size of buffer
 *
 * Return: pointer to r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int tempSizeR = size_r;
	int bufferPlacer = 0;
	int n1Length = 0, n2Length = 0;
	int result = 0, carryStore = 0;

	while (*(n1 + n1Length) != '\0')
		n1Length++;
	while (*(n2 + n2Length) != '\0')
		n2Length++;

	/* account for 9999, 1, size_r:4, and extra space needed for '\0' */
	if (n1Length > size_r - 2 || n2Length > size_r - 2)
		return (0);
	n1Length--, n2Length--; /* set element behind null byte */

	while (size_r >= 0)
	{	
		if (size_r == tempSizeR) /* set last byte to null byte */
		{
			r[size_r--] = '\0';
			continue;
		}
		if (n1Length < 0 && n2Length < 0 && carryStore == 0)
		{
			r[size_r--] = FILL;
			continue; /* fill in rest with constants's */
		}
		else if (n1Length < 0 && n2Length < 0 && carryStore != 0)
			result = carryStore;
		else if (n1Length < 0)
			result = n2[n2Length] + carryStore - '0';
		else if (n2Length < 0)
			result = n1[n1Length] + carryStore - '0';
		else /* normal case */
		{
			result = (n1[n1Length] - '0') + (n2[n2Length] - '0') + carryStore;
		}
		carryStore = 0;
		if (result > 9)
		{
			carryStore = 1;
			result = result - 10;
		}
		n1Length--, n2Length--;
		r[size_r--] = result + '0';
	}
	/* below loop moves elements to beginning of array */
	size_r = 0;
	while (size_r < tempSizeR)
	{
		if (r[size_r] != FILL)
		{
			r[bufferPlacer++] = r[size_r];
			r[size_r] = '\0';
		}
		else
			r[size_r] = '\0';
		size_r++;
	}

	return (r);
}
