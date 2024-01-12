/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
    /* values */
    char *str;
    unsigned int len;

    /* pointer */
    struct list_s *next;
} list_n;

#include <stddef.h>


/* FNC PROTOTYPE */
size_t print_list(const list_n *h);
