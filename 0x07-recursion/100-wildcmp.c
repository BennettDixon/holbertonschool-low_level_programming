int recursive_check(char *s1, char *s2, int wildC);
/**
 * wildcmp - compares two strings, supports wildcard '*'
 *
 * @s1: string 1 to compare to s2
 * @s2: string 2 to compare to s1
 *
 * Return: 1 if identical, 0 otherwise, -1 for error
 */
int wildcmp(char *s1, char *s2)
{
	return (recursive_check(s1, s2, 0));
}
/**
 * recursive_check - checks for wild cards recursively
 *
 * @s1: string 1 to check (no wild cards)
 * @s2: string to to check (can contain wildcards)
 * @wildC: counter to see if wildcard is present
 *
 * Return: 1 if identical, 0 for not, -1 for error
 */
int recursive_check(char *s1, char *s2, int wildC)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	if (*s2 == '*')
		return (recursive_check(s1, s2 + 1, ++wildC));
	else if (*s1 != *s2 && wildC > 0) /* skip to next rel char */
	{
		if (!*s1)
			return (0);
		return (recursive_check(s1 + 1, s2, wildC));
	}
	else if (*s1 == *s2 && wildC == 0) /* char match, next char for each str */
		return (recursive_check(s1 + 1, s2 + 1, 0));
	else if (*s1 == *s2 && wildC > 0)
	{
		if (!recursive_check(s1 + 1, s2 + 1, 0))
			return (recursive_check(s1 + 1, s2, wildC));
		return (recursive_check(s1 + 1, s2 + 1, wildC));
	}
	else if (*s1 != *s2 && wildC == 0) /* non matching and no wildC */
		return (0);
	return (-1); /* something unexpected occured, return -1 for error */
}
