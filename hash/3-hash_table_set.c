#include "hash_tables.h"

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    char *val = NULL;
    char *_key = NULL;
    unsigned long int hash = hash_djb2((const unsigned char*)key);
    unsigned long int idx = hash % ht->size;

    if (key == NULL)
    {
        return (0);
    }

    val = strdup(value);
    _key = strdup(key);

    if (ht == NULL)
    {
        hash_table_create(1024);
    }


    if (ht->array[idx] == NULL)
    {
        ht->array[idx]->key = _key;
        ht->array[idx]->value = val;
        ht->array[idx]->next = NULL;
    }
    else
    {
        hash_node_t *ht_temp = malloc(sizeof(hash_node_t));

        ht_temp->next = ht->array[idx];
        ht_temp->key = _key;
        ht_temp->value = val;
        ht->array[idx] = ht_temp;
    }
    return (1);
}