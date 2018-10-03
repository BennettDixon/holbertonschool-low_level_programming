int check_palindrome_recursive(char *start, char *end);
/**
 * is_palindrome - checks if string is palindrome
 *
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	char *end = s;

	if (!*s) /* empty string */
		return (1);
	while (*end)
		end++;
	end--; /* set end to char before null byte */
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
