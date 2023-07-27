#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main(void)
{
    //create nodes
    struct node *newNode, *nodeB, *nodeC, *head;
    newNode = (struct node*)malloc(sizeof(struct node));
    nodeB = (struct node*)malloc(sizeof(struct node));
    nodeC = (struct node*)malloc(sizeof(struct node));
    
    if (newNode == NULL && nodeB == NULL && nodeC == NULL)
    {
        printf("Memory allocation failed!\n");
        return (1);
    }

    newNode->data = 87;
    newNode->next = NULL;

    head = newNode;

    struct node *temp;
    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeB;
    temp= temp->next;
    temp->data = 98;
    temp->next = nodeC;
    temp= temp->next;
    temp->data = 17;
    temp->next = NULL;

    /* print a values */
    temp = head;
    while (temp->next != NULL)
    {
        /* code */
        printf("%d ---->", temp->data);
        temp = temp->next;
    }
        printf("%d", temp->data);
    
    free(newNode);
    return (0);
}