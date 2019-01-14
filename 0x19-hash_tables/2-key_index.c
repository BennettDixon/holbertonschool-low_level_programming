#include "hash_tables.h"
/**
 * key_index - gets the index of given key for hashtable
 * @key: str containing key
 * @size: size of the hash table's array
 *
 * Return: index of given key in hash_table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_key;

	hash_key = hash_djb2((unsigned char *)key);
	return (hash_key % size);
}
