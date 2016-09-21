#ifndef QUEUE_H
#define QUEUE_H
#include "tree.h"

typedef struct q_element{
    Node * dat;
    struct q_element *next;
} q_element;

typedef struct{
    q_element *front, *rear;
    int num_of_elements;
} Queue;

Queue * create_queue();
void enqueue(Queue *, Node *);
Node * dequeue(Queue *);
int q_isEmpty(Queue *);
int sizeof_queue(Queue *);


#endif /*QUEUE_H*/