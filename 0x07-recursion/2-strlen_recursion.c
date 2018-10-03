/**
 * _strlen_recursion - gets strlen of s via recursive algorithm
 *
 * @s: string to check length of
 *
 * Return: int containing length of string
 */
int _strlen_recursion(char *s)
{
	if (!*s)
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
