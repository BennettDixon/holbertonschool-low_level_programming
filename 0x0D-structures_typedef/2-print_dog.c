#include <stdio.h>
#include "dog.h"
#define NILL "(nil)"
/**
 * print_dog - prints contents of struct dog
 *
 * @d: pointer to struct of type struct dog
 *
 * Return: always void
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;
	if (d->name == NULL)
		d->name = NILL;
	if (d->owner == NULL)
		d->owner = NILL;
	printf("Name: %s\nAge: %0.6f\nOwner: %s\n", d->name, d->age, d->owner);
}
