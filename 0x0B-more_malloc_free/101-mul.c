#include <stdio.h>
#include <stdlib.h>
int contains_non_numeric(char *str);
int _atoi(char *s);
char *infinite_add(char *n1, char *n2, char *r, int size_r);
void move_int_end_to_beg(char *str, int size, char fill);
char *multiply_strings(char *s1, char *s2, char *buff, unsigned int size_b);
void *set_mem(void *p, unsigned int nmemb, unsigned int size, char ch);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strlen(char *s);
/**
 * main - entry point for program
 *
 * @argc: count of arguments
 * @argv: list of pointers to arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	unsigned int mem;
	int i;

	char *ret;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}
	for (i = 1; i < argc; i++)
	{
		if (contains_non_numeric(argv[i]))
		{
			printf("Error\n");
			return (98);
		}
	}
	mem = _strlen(argv[1]) + _strlen(argv[2]) + 1;
	ret = _calloc(mem, sizeof(char));
	if (ret == NULL)
		return (98);
	ret = multiply_strings(argv[1], argv[2], ret, mem);
	printf("%s\n", ret);
	return (0);
}
/**
 * multiply_strings - multiplies two strings together
 *
 * @s1: string 1 to multiply with string 2
 * @s2: string 2 to multiply with string 1
 * @buff: buffer to store result in
 * @size_b: size of buffer in bytes
 *
 * Return: pointer to beginning of buffer
 */
char *multiply_strings(char *s1, char *s2, char *buff, unsigned int size_b)
{
	char *smaller, *larger;
	int i = 0, res = 0;

	smaller = (_strlen(s1) > _strlen(s2)) ? s1 : s2;
	larger = (smaller == s1) ? s2 : s1;
	res =  _atoi(smaller);
	while (i < res)
	{
		buff = infinite_add(buff, larger, buff, size_b);
		i++;
	}
	return (buff);
}
/**
 * _strlen - gets length of string
 *
 * @s: string to get length of
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
/**
 * contains_non_numeric - checks if string has non numeric values
 *
 * @str: string to check
 *
 * Return: 1 if contains non numeric values, 0 if only numeric
 */
int contains_non_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}
/**
 * _atoi - converts string to integer
 *
 * @s: string to convert from
 *
 * Return: integer from conversion, -1 if contains nonint
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char working = 0;

	while (*s)
	{
		if (*s == '-')
			sign = sign * -1;
		if (*s >= '0' && *s <= '9')
		{
			working = 1;
			total = total * 10 + *s - '0';
		}
		else if (*s < '0' || *s > '9')
		{
			if (working)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-(total));
	return (total);
}
/**
 * infinite_add - adds two numbers
 *
 * @n1: *char - first number
 * @n2: *char - second number
 * @r:  *char - buffer where result is stored
 * @size_r: int - size of buffer
 *
 * Return: pointer to r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int tempSizeR = size_r;
	char fill = 'd';
	int n1Length = 0, n2Length = 0, result = 0, carryStore = 0;

	while (*(n1 + n1Length) != '\0')
		n1Length++;
	while (*(n2 + n2Length) != '\0')
		n2Length++;
	/* account for 9999, 1, size_r:4, and extra space needed for '\0' */
	if (n1Length > size_r - 2 || n2Length > size_r - 2)
		return (0);
	n1Length--, n2Length--; /* set element behind null byte */
	while (size_r >= 0)
	{
		if (size_r == tempSizeR)
		{ /* set last byte to end of string char or 'null byte' */
			r[size_r--] = '\0';
			continue;
		}
		if (n1Length < 0 && n2Length < 0 && carryStore == 0)
		{
			r[size_r--] = fill;
			continue; /* fill in rest with constants's */
		}
		else if (n1Length < 0 && n2Length < 0 && carryStore != 0)
			result = carryStore;
		else if (n1Length < 0)
			result = n2[n2Length] + carryStore - '0';
		else if (n2Length < 0)
			result = n1[n1Length] + carryStore - '0';
		else /* normal case */
		{
			result = (n1[n1Length] - '0') + (n2[n2Length] - '0') + carryStore;
		}
		carryStore = 0;
		if (result > 9)
		{
			carryStore = 1;
			result = result - 10;
		}
		n1Length--, n2Length--;
		r[size_r--] = result + '0';
	}
	move_int_end_to_beg(r, tempSizeR, fill);
	return (r);
}
/**
 * move_int_end_to_beg - moves integer from end of str to beginning
 *
 * @arr: string to change
 * @arrSize: size of string including null byte
 * @fillChar: character used to fill string that isn't part being moved
 *
 * Return: always void
 */
void move_int_end_to_beg(char *arr, int arrSize, char fillChar)
{
	int i = 0;
	int bufferPlacer = 0;
	/* below loop moves elements to beginning of array */
	while (i < arrSize)
	{
		if (arr[i] != fillChar)
		{
			arr[bufferPlacer++] = arr[i];
			arr[i] = '\0';
		}
		else
			arr[i] = '\0';
		i++;
	}
}
#include <stdlib.h>
void *set_mem(void *p, unsigned int nmemb, unsigned int size, char ch);
/**
 * _calloc - allocates memory for an array, and inits
 *
 * @nmemb: number of members in array
 * @size: size of each member
 *
 * Return: void pointer to beginning of alloc/init'ed memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ret;

	if (nmemb < 1 || size < 1)
		return (NULL);
	ret = malloc(nmemb * size);
	if (ret == NULL)
		return (NULL);
	ret = set_mem(ret, nmemb, size, '\0');
	return (ret);
}
/**
 * set_mem - sets memory for void pointer
 *
 * @p: pointer to beginning of memory to set
 * @nmemb: number of members of array
 * @size: size of elements of array
 * @ch: character to set memory to
 *
 * Return: void pointer to beginning of set memory
 */
void *set_mem(void *p, unsigned int nmemb, unsigned int size, char ch)
{
	char *cast = p;
	unsigned int i = 0;

	while (i < nmemb * size)
		cast[i++] = ch;
	return (p);
}
