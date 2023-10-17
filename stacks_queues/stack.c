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
    printf("popped --> %d\n", poped_i);

    return (0);
}

int push(int item)
{
    /*Adding to the stack*/
    head = createNode(head, item);
    printf("head --> %d\n", head->i);
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
