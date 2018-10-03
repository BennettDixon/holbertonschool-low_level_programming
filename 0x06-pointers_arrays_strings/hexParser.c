#include <stdio.h>

int main(void)
{
	FILE *pF;
	char buff[1000];

	pF = fopen("hexToParse", "r");
	if (!pF)
		return (-1);
	while (fgets(buff, 1000, pF) != NULL) {}
	fclose(pF);
	printf("%s", buff);
	return (0);
}
