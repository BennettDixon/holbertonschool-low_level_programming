#define FILL 100 /* fill with 'd' */
void move_int_end_to_beg(char *str, int size, char fill);
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
	int n1Length = 0, n2Length = 0, result = 0, carryStore = 0;

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
		if (size_r == tempSizeR)
		{ /* set last byte to end of string char or 'null byte' */
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
	move_int_end_to_beg(r, tempSizeR, FILL);
	return (r);
}
/**
 * move_int_end_to_beg - moves integer from end of str to beginning
 *
 * @arr: string to change
 * @arrSize: size of string including null byte
 * @fillChar: character used to fill string that isn't part being moved
 *
 * Return: always void
 */
void move_int_end_to_beg(char *arr, int arrSize, char fillChar)
{
	int i = 0;
	int bufferPlacer = 0;
	/* below loop moves elements to beginning of array */
	while (i < arrSize)
	{
		if (arr[i] != fillChar)
		{
			arr[bufferPlacer++] = arr[i];
			arr[i] = '\0';
		}
		else
			arr[i] = '\0';
		i++;
	}
}
