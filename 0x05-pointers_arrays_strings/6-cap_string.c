int char_is_seperator(char ch);
/**
 * cap_string - capitalizes first letters of str
 *
 * @str: string to capitalize letters
 *
 * Return: pointer to str
 */
char *cap_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i == 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		if (char_is_seperator(str[i]))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[i + 1] -= 32;
		}
		i++;
	}
	return (str);
}
/**
 * char_is_seperator - checks if char is a seperator
 *
 * @ch: character to check
 *
 * Return: 1 if seperator, 0 otherwise
 */
int char_is_seperator(char ch)
{
	int i = 0;
	int numSeperators = 13;
	char seperators[] = { ' ', '\t', '\n', ',',
				';', '.', '!', '?', '"',
				'(', ')', '{', '}' };
	while (i < numSeperators)
	{
		if (ch == seperators[i++])
			return (1);
	}
	return (0); /* didn't find one */
}
