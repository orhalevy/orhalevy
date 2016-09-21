#ifndef STACK_H
#define STACK_H
#include "tree.h"

typedef struct stack{
    Node * arr[50];
    int top;
}Stack;

Stack * createStack(); //Function to create a stack
void push(Stack *, Node *); //Func to push - need a ptr to the stack, and a value to push
Node * pop(Stack *); //Func to pop. Need a ptr and returns a value
int top(Stack *);
int isEmpty(Stack *);
int isFull(Stack *);

#endif