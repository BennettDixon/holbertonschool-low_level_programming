/**
 * string_toupper - converts string to upper case
 *
 * @str: string to convert
 *
 * Return: char pointer to converted string
 */
char *string_toupper(char *str)
{
	char *start = str;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (start);
}
