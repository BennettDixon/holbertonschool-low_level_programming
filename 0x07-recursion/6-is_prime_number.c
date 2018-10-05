int prime_checker(int n, int prevCheck);
int _find_sqrt(int prev, int find);
int _sqrt_recursion(int n);
/**
 * is_prime_number - checks if n is a prime number
 *
 * @n: int to check if it is prime or not
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1) /* edge case */
		return (0);
	return (prime_checker(n, _sqrt_recursion(n)));
}
/**
 * prime_checker - checks if n is prime number using recursion
 *
 * @n: int to see if isprime
 * @prevCheck: previous value checked to see if n % prevCheck == 0
 *
 * Return: -1 if error, 1 if no value divides by n (prime), 0 if nonprime
 */
int prime_checker(int n, int prevCheck)
{
	if (n == prevCheck)
		return (-1);
	if (prevCheck < 2)
		return (1);
	if (n % prevCheck == 0)
		return (0);
	return (prime_checker(n, prevCheck - 1));
}
/**
 * _sqrt_recursion - finds square root of n, recursively
 *
 * @n: int to find sqroot from
 *
 * Return: sqroot, -1 if no natural sqroot for n
 */
int _sqrt_recursion(int n)
{
	if (n <= 0) /* error case */
		return (-1);
	return (_find_sqrt(1, n));
}
/**
 * _find_sqrt - finds square root recursively, needs prev param
 *
 * @prev: previous result of function
 * @find: constant int to find sq root for
 *
 * Return: square root of find, or -1 if not found
 */
int _find_sqrt(int prev, int find)
{
	if (prev > find) /* didn't find a nr, there was remainder */
		return (-1);
	if (prev * prev == find) /* natural root found */
		return (prev);
	return (_find_sqrt(prev + 1, find)); /* not super efficient */
}
