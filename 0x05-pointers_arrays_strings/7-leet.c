char get_leet(char);
/**
 * leet - transalte to leet speak
 *
 * @str: string to convert
 *
 * Return: pointer to str
 */
char *leet(char *str)
{
	char temp;
	int i = 0;

	while (str[i] != '\0')
	{
		temp = get_leet(str[i]);
		if (temp != '\0')
			str[i] = temp;
		i++;
	}
	return (str);
}
/**
 * get_leet - gets leet character for english char
 *
 * @nonLeet: english character to convert/check
 *
 * Return: char: leet version if exists, otherwise null byte
 */
char get_leet(char nonLeet)
{
	int arrSize = 10;
	char leet[] =    {'4', '3', '0', '7', '1', '4', '3', '0', '7', '1', '\0'};
	char english[] = {'a', 'e', 'o', 't', 'l', 'A', 'E', 'O', 'T', 'L', '\0'};
	int i = 0;

	while (english[i] != nonLeet && i < arrSize)
		i++;
	return (leet[i]); /* i will be arrSize+1 if no english matches ch */
}
