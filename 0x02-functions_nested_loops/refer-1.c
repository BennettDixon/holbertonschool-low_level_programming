#include <stdio.h>

int main(void)
{
	int n;

	n = 'a';

	while(n <= 'z')
		putchar(n++);
	putchar('\n');
}
