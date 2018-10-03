/**
 * factorial - returns factorial of n using recursion
 *
 * @n: int paramater to return factorial of
 *
 * Return: factorial of n
 */
int factorial(int n)
{
	if (n < 0) /* error */
		return (-1);
	if (n <= 1) /* base case */
		return (1);
	return (n * factorial(n - 1));
}
