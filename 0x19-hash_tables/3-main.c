#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    printf("%d\n", hash_table_set(ht, "betty", "holberton"));
    printf("value for added node in main: %s\n", ht->array[173]->value);
    return (EXIT_SUCCESS);
}
