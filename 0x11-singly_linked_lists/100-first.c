#include <stdio.h>

/* Using constructors in C! Who knew!? */
void main_constructor(void) __attribute__((constructor));
/**
 * main_constructor - constructor function that runs before main ()
 *
 * Return: always void
 */
void main_constructor(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
