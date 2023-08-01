#include "lists.h"

/**
 * listint_len - Counts the number of elements in a linked list.
 * @h: Pointer to the head of the linked list.
 *
 * Return: The number of elements in the linked list.
 */

size_t listint_len(const listint_t *h)
{
    const listint_t *temp = h;
    unsigned int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return (count);
}