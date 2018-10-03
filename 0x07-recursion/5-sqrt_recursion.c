int _find_sqrt(int prev, int find);
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
