#include "main.h"

struct node *head = NULL;

/**
 * main -  Entry point
 *
 * Return: on sucess 0.
*/
int main(void)
{
    push(5);
    push(10);
    push(2);
    int poped_i = pop(head->next);
    /*            TEST               */
    /*printf("popped --> %d\n", poped_i);*/

    int peeked = peek();
    /*            TEST               */
    /*printf("peeked --> %d\n", peeked);*/

    bool check = is_empty();
    /*            TEST               */
    printf("it is --> %d\n", check);

    return (0);
}

int peek(void)
{
    if (!head)
    {
        printf("Stack is empty");
        return (-1);
    }
    struct node *tmp = head;
    while(tmp->next)
    {
        tmp = tmp->next;
    }
    return (tmp->i);
}

int push(int item)
{
    /*Adding to the stack*/
    head = createNode(head, item);
    /*            TEST               */
    /* printf("head --> %d\n", head->i); */
}

int pop(struct node *remove)
{
    int x;

    if (!remove)
    {
        printf("Empty stack!");
        return (-1);
    }
    if (!remove->next)
    {
        x = remove->i;
        remove = NULL;
        free(remove->next);
        return (x);
    }
    while (remove->next->next)
    {
        remove = remove->next;
    }
    x = remove->next->i;
    free(remove->next->next); /*free the last memory before lossing it*/
    remove->next = NULL;
    return (x);
}

struct node *createNode(struct node *head, int x)
{
    struct node *new_node = NULL;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Malloc failed!");
        exit(-1);
    }

    new_node->i = x;

    if (head == NULL){
        head = new_node;
    }
    else{
        struct node *tmp = head;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
    return (head);
}

bool is_empty(void)
{
    if (!head)
    {
        printf("is empty\n");
        return true;
    }
    else
    {
        printf("is not empty\n");
        return false;
    }
}