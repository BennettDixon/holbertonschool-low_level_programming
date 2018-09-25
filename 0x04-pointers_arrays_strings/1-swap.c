/**
 * swap_int - swap to integer values
 *
 * @a: first value to swap
 * @b: second value to swap
 *
 * Return: always void
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
