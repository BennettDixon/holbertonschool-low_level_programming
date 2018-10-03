int check_palindrome_recursive(char *start, char *end);
int _strlen_recursion(char *s);
/**
 * is_palindrome - checks if string is palindrome
 *
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	char *end;
	int sLength;

	if (!*s) /* empty string */
		return (1);
	sLength = _strlen_recursion(s);
	end = (s + (sLength - 1)); /* set end to char before null byte */
	return (check_palindrome_recursive(s, end));
}
/**
 * check_palindrome_recursive - checks if string is palindrome
 *
 * @start: starting point of string to check
 * @end: last valid character in string before null byte
 *
 * Return: 1 if palindrome, 0 if failure (not palindrome)
 */
int check_palindrome_recursive(char *start, char *end)
{
	if (*start != *end)
		return (0);
	if (start > end) /* checked all chars up to middle */
		return (1);
	return (check_palindrome_recursive(start + 1, end - 1));
}
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
