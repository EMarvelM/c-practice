#ifndef MAIN_H
#define MAIN_H

struct node{
    int i;
    struct node *next;
}xzon;


#include <stdio.h>
#include <stdlib.h>

struct node *createNode(struct node *head, int x);
int pop(struct node *remove);

#endif /* MAIN_H */