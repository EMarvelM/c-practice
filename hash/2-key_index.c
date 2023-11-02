#include "hash_tables.h"

/**
 * key_index - determine the index of a key
 * @key: the key
 * @size: size of the array in the hash table
 *
 * Return: the index
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int idx = hash_djb2(key) % size;

	return (idx);
}
