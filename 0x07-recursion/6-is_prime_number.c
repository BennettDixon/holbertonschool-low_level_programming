int prime_checker(int n, int prevCheck);
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
	return (prime_checker(n, n - 1));
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
