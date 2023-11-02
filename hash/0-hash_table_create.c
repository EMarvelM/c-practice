#include "hash_tables.h"

hash_table_t *hash_table_create(unsigned long int size)
{
    unsigned int i;
    hash_table_t *new_ht = NULL;

    new_ht = malloc(sizeof(hash_table_t));
    if (new_ht == NULL)
    {
        return (NULL);
    }

    hash_node_t **lis_t = malloc(sizeof(hash_node_t *) * size);
    if (lis_t == NULL)
    {
        return (NULL);
    }
    new_ht->array = lis_t;

    for (i = 0; i < size; i++)
    {
        new_ht->array[i] = NULL;
    }

    return (new_ht);
}
