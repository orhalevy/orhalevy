#include <stdio.h>
#include "stack.h"
#include "tree.h"
#include <stdlib.h>

Stack * createStack(){
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    stack->top = -1; //Initialize the top as -1 (So that the first value will go to [0])
    return stack;
}

void push(Stack * stack, Node * toPush){
    if(isFull(stack)){
        printf("[ERROR] Stack Overflow\n");
        return;
    }
    
    stack->top++; //Increase the top
    stack->arr[stack->top] = toPush; //push the value
}

Node * pop(Stack * stack){
    if(isEmpty(stack))
        return 0; //Error: underflow
    
    stack->top--; //Reduce the top
    return stack->arr[stack->top+1]; //Return the old top value
}

int isEmpty(Stack * stack){
    if(stack->top < 0)
        return 1; //Is Empty
    
    return 0; //Not empty
}

int isFull(Stack * stack){
    if(stack->top == 19)
        return 1; //Is Full
    
    return 0; //Not full
}