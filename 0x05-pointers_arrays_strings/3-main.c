#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char s1[] = "Hel";
    char s2[] = "Wo";

    printf("%d\n", strcmp(s1, s2));
    printf("%d\n", strcmp(s2, s1));
    printf("%d\n", strcmp(s1, s1));
    return (0);
}
