#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - print all element of a dll
 * @dlistint_t: the head to the list
 *
 * Return: size of the ddl nodes
*/

size_t print_dlistint(const dlistint_t *h)
{
    /* iterate the doubled linked list and print each value */
    dlistint_t *temp = h->next->prev;
    size_t count = 0;

    while (temp)
    {
        printf("%d\n", temp->n);
        count++;
        if (temp != NULL)
        {
            temp = temp->next;
        }
    }
    return (count);
}