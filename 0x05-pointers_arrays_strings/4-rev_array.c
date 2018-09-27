/**
 * reverse_array - reverses an array
 *
 * @a: an array of ints
 * @n: size of array
 *
 * Return: always void
 */
void reverse_array(int *a, int n)
{
	int start = 0;
	int store;

	while (start < n - 1)
	{
		store = a[n - 1];
		a[n - 1] = a[start];
		a[start] = store;
		n--;
		start++;
	}
}
