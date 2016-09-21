#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue * create_queue(){
    Queue * queue=(Queue *) malloc(sizeof(Queue)); //Allocate memory for the queue
    if(!queue){ //In case of failed allocation
        printf("Error! Could not allocate memory for the queue\n");
        exit(1); //Exit with error
    }
    
    //Initialize an empty queue
    queue->front=NULL;
    queue->rear=NULL;
    queue->num_of_elements=0;
    
    return queue;
}

int q_isEmpty(Queue *queue){
    if(queue->num_of_elements==0)
        return 1;
    return 0;
}

void enqueue(Queue * queue, Node * element){
    q_element * temp=(q_element *) malloc(sizeof(q_element));
    if(!temp){
        printf("Error! Could not allocate memory for the element\n");
        exit(1); //Exit with error
    }
    
    temp->dat=element;
    temp->next=NULL;
    if(queue->num_of_elements!=0){ //In case of non empty queue
        queue->rear->next=temp; //Set the new element as the next of the rear element
        queue->rear=queue->rear->next; //Set the new element as the new rear element
    } else{ //In case of an empty queue
        queue->front=queue->rear=temp;
    }
    
    queue->num_of_elements++;
}

Node * dequeue(Queue *queue){
    q_element * temp_element;
    
    if(q_isEmpty(queue))
        return NULL;
    
    temp_element=queue->front; //Save the current front of the queue
    queue->front=temp_element->next; //Set the front as the next element on the queue
    queue->num_of_elements--;
    
    return temp_element->dat;
}