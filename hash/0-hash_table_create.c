#include "hash_tables.h"

hash_table_t *hash_table_create(unsigned long int size)
{
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
    return (new_ht);
}
