/**
 * _strstr - locates a substring
 *
 * @haystack: string to search
 * @needle: substring to find
 *
 * Return: pointer to start of needle
 * in haystack
 */
char *_strstr(char *haystack, char *needle)
{
	char *occurance;
	char *tHayStack = haystack;
	char *tNeedle = needle;

	while (*tHayStack)
	{
		if (*tHayStack == *tNeedle) /* first ch match */
		{
			occurance = tHayStack;
			while (*tNeedle) /* check if match */
			{
				if (*tHayStack++ != *tNeedle++)
				{ /* not a match, reset pointer to first occurance */
					tHayStack = occurance;
					break;
				}
			}
			if (occurance != tHayStack) /* didn't reset, found match */
				return (occurance);
		}
		tHayStack++;
	}
	return (tHayStack); /* didn't find match */
}
