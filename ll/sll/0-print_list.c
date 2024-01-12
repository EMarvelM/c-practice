#include <stdio.h>
#include <string.h>
#include "lists.h"

size_t print_list(const list_n *h)
{
    const struct list_s *temp = h;
    int count = 0;

    while(temp != NULL)
    {
        if (temp->str == NULL)
            printf("[%u] (nil)\n", temp->len);
        else
            printf("[%u] %s\n", temp->len, temp->str);

        temp = temp->next;
        count++;
    }

    return (count);

}