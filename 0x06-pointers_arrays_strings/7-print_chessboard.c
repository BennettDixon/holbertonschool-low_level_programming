#include "holberton.h"
/**
 * print_chessboard - prints out a chessboard
 *
 * @a: chessboard to print, 2D array [8] columns
 *
 * Return: always void
 */
void print_chessboard(char (*a)[8])
{
	int subC, primC = 0;

	while (primC < 8)
	{
		subC = 0;
		while (subC < 8)
			_putchar(a[primC][subC++]);
		_putchar('\n');
		primC++;
	}
}
