#include <stdlib.h>
int get_word_length(char *str);
int get_word_count(char *str);
char *get_next_word(char *str);
/**
 * strtow - takes a string and seperates its words
 *
 * @str: string to seperate into words
 *
 * Return: 2D array of pointers to each word
 */
char **strtow(char *str)
{
	char **words;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str);
	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = get_word_length(str);
		if (*str == ' ' || *str == '\t')
			str = get_next_word(str);
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /* set end of str */
		str = get_next_word(str);
		i++;
	}
	words[i] = NULL; /* last element is null for iteration */
	return (words);
}
/**
 * get_word_length - gets the word length of cur word in str
 *
 * @str: string to get word length from current word
 *
 * Return: word length of current word
 */
int get_word_length(char *str)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (*(str + i) == ' ' || *(str + i) == '\t')
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && (*(str + i) == ' ' || *(str + i) == '\t'))
			break;
		i++;
	}
	return (wLen);
}
/**
 * get_word_count - gets the word count of a string
 *
 * @str: string to get word count from
 *
 * Return: the word count of the string
 */
int get_word_count(char *str)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (*(str + i) == ' ' || *(str + i) == '\t')
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}
/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get next word from
 *
 * Return: pointer to first char of next word
 */
char *get_next_word(char *str)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (*(str + i) == ' ' || *(str + i) == '\t')
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
