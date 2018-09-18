#include <stdio.h>

int main(void)
{
	int h1, h2, n1, n2;

	h1, h2, n1, n2 = 0;

	while(h1 <= 9)
	{
		h2 = h1;
		while(h2 <= 8)
		{
			n1 = h1;
			while(n1 <= 9)
			{
				n2 = n1;
				while(n2 <= 9)
				{
					putchar(h1 + '0');
					putchar(h2 + '0');
					putchar(n1 + '0');
					putchar(n2 + '0');
					if (!(n1 == 9 && n2 == 9 && h1 == 9))
					{
						putchar(',');
						putchar(' ');
					}
					n2++;
				}
			n1++;
			}
		h2++;
		}
	h1++;
	}
	putchar('\n');
}
