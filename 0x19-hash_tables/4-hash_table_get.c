#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - gets a hash table key value pair in hash table
 * @ht: hash table to pull value from
 * @key: key to generate hash value and index off
 *
 * Return: value associated with key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int key_i = 0;
	char *value = NULL;
	hash_node_t *poss_nodes;

	if (!ht || !key)
		return (NULL);
	else if (strlen(key) == 0)
		return (NULL);

	key_i = key_index((unsigned char *)key, ht->size);
	if ((ht->array)[key_i] == NULL)
		return (NULL);

	poss_nodes = ht->array[key_i];
	while (!value)
	{
		if (strcmp(poss_nodes->key, key) == 0)
			value = poss_nodes->value;
		poss_nodes = poss_nodes->next;
	}
	return (value);
}
