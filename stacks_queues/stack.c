#include "main.h"

/**
 * main -  Entry point
 *
 * Return: on sucess 0.
*/
int main(void)
{
    int x = 5; //get this from the user (maybe in a loop)
    /*Starting the stack*/
    struct node *head;
    head = NULL;

    head = createNode(head, x);

    return (0);
}


int pop(struct node remove)
{
    int i;
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
