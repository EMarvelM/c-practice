#ifndef MAIN_H
#define MAIN_H

struct node{
    int i;
    struct node *next;
}xzon;


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node *createNode(struct node *head, int x);
int pop(struct node *remove);
int push(int item);
int peek(void);
bool is_empty(void);

#endif /* MAIN_H */