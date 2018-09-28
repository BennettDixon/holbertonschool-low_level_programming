#define rotn 13

char get_rot(char);
/**
 * rot13 - encode str to rot13
 *
 * @str: string to convert
 *
 * Return: pointer to str
 */
char *rot13(char *str)
{
	char temp;
	int i = 0;

	while (str[i] != '\0')
	{
		temp = get_rot(str[i]);
		if (temp != 0)
			str[i] = temp;
		i++;
	}
	return (str);
}
/**
 * get_rot - gets leet character for english char
 *
 * @conv: english character to convert/check
 *
 * Return: char rot13 representation
 */
char get_rot(char conv)
{
	char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
			   'h', 'i', 'j', 'k', 'l', 'm', 'n',
			   'o', 'p', 'q', 'r', 's', 't', 'u',
			   'v', 'w', 'x', 'y', 'z',
			   'A', 'B', 'C', 'D', 'E', 'F', 'G',
			   'H', 'I', 'J', 'K', 'L', 'M', 'N',
			   'O', 'P', 'Q', 'R', 'S', 'T', 'U',
			   'V', 'W', 'X', 'Y', 'Z', 0};
	int rotTranslate[] = { rotn, rotn, rotn, rotn, rotn,
			       rotn, rotn, rotn, rotn, rotn,
			       rotn, rotn, rotn, -(rotn), -(rotn),
			       -(rotn), -(rotn), -(rotn), -(rotn), -(rotn),
			       -(rotn), -(rotn), -(rotn), -(rotn), -(rotn),
			       -(rotn), /* end lowercase */
			       rotn, rotn, rotn, rotn, rotn,
			       rotn, rotn, rotn, rotn, rotn,
			       rotn, rotn, rotn, -(rotn), -(rotn),
			       -(rotn), -(rotn), -(rotn), -(rotn), -(rotn),
			       -(rotn), -(rotn), -(rotn), -(rotn), -(rotn),
			       -(rotn), 0};
	int arrSize = 26 * 2;
	int i = 0;

	while (conv != alphabet[i] && i < arrSize)
		i++;
	return (alphabet[i] + rotTranslate[i]);
}
