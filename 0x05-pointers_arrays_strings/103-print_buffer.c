#include <stdio.h>
#include <stdlib.h>
void print_hex_line(char *buffer, int numBitsInLine, int currentPosition);
void print_buffer_line(char *b, int n, int cur);
/**
 * print_buffer - prints contents of a buffer
 *
 * @b: buffer to print
 * @size: size of buffer
 *
 * Return: always void
 */
void print_buffer(char *b, int size)
{
	int quo, rem, i = 0;
	int bitCounter = 0, numBitsInLine;

	if (size == 0)
		return;
	quo = size / 10;
	rem = size % 10;
	if (rem)
		quo++;
	while (i < quo) /* loop through 10 bits at a time */
	{
		numBitsInLine = (size - rem) > bitCounter ? 10 : rem;
		printf("%.8x: ", bitCounter);
		print_hex_line(b, numBitsInLine, bitCounter);
		print_buffer_line(b, numBitsInLine, bitCounter);
		putchar('\n');
		bitCounter += 10;
		i++;
	}
}
/**
 * print_hex_line - prints chars of buffer as hex in sets of 2
 *
 * @b: buffer to print line from
 * @numBitsInLine: number of bits in line, print spaces to fill in
 * @currentPos: position in array of starting point of line
 *
 * Return: always void
 */
void print_hex_line(char *b, int numBitsInLine, int currentPos)
{
	int nestedCounter = 0;

	while (nestedCounter < 10)
	{
		if (nestedCounter >= numBitsInLine)
			printf("  ");
		else
			printf("%.2x", b[currentPos + nestedCounter]);
		if (nestedCounter % 2)
			putchar(' ');
		nestedCounter++;
	}
}
/**
 * print_buffer_line - prints chars of buffer as buffchar in sets of 2
 *
 * @b: buffer to print line from
 * @numBitsInLine: number of bits in line, print spaces to fill in
 * @currentPos: position in array of starting point of line
 *
 * Return: always void
 */
void print_buffer_line(char *b, int numBitsInLine, int currentPos)
{
	int nestedCounter = 0;

	while (nestedCounter < 10)
	{
		if (nestedCounter >= numBitsInLine)
			break;
		else if (b[currentPos + nestedCounter] >= 32
			&& b[currentPos + nestedCounter] < 127)
		{
			printf("%c", b[currentPos + nestedCounter]);
		}
		else
			printf(".");
		nestedCounter++;
	}
}
