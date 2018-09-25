#include <stdio.h>
/**
 * _atoi - converts string to integer
 *
 * @s: string to convert from
 *
 * Return: integer from conversion
 */
int _atoi(char *s)
{
	char sign = 0;
	int total = 0;
	char working = 0;

	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			working = 1;
			if (sign == 0)
			{
				sign = *(s - 1);
				if (sign != '-' && sign != '+')
					sign = '+';
			}
			total = total * 10 + *s - '0';
		}
		else if (*s < '0' || *s > '9')
		{
			if (working) 
				break;
		}
		s++;
	}
	if (sign == '-')
		total = (-(total));
	return (total);
}
