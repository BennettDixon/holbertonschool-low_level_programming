#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - creates a hash table
 * @size: size of hash table to create
 *
 * Return: pointer to new hash_table_t in memory (heap)
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table = NULL;

	new_table = malloc(sizeof(hash_table_t));
	if (!new_table)
		return (NULL);
	new_table->size = size;
	new_table->array = malloc(sizeof(hash_node_t) * size);
	if (!new_table->array)
	{
		free(new_table);
		return (NULL);
	}
	return (new_table);
}
