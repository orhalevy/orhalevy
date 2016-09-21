#include "tree.h"
#include "stack.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 

//Functions
void print_inorder(Node *);
void print_levels(Node *);
Node * build_tree();
//End of Functions

void main() {
    Node *root=NULL;
    int menu=6;
    printf("Menu:\n1. Create tree\n2. Print tree inorder\n3. Print tree by levels\n4. Destroy tree\n0. Exit\n=>");
    scanf_s("%d", &menu);
    while(menu!=0){
            if(menu==0){
                printf("Exiting...\n");
                exit(0);
            }
            if(menu==1){
                root=build_tree();
                printf("Root adress: %p\n", root);
            }
            else if(menu==2){
                print_inorder(root);
            }
            else if(menu==3){
                print_levels(root);
            }
            else if(menu==4){
                destroy_tree(root);
            }
            else{
                printf("Wrong input. Exiting");
                exit(1); //Exit with error (Unknown input)
            }
            while(getchar()!='\n');
            printf("Input: ");
            scanf_s("%d", &menu);
        }
}

void print_inorder(Node *root){
    Node *current=root;
    Stack * stack;
    while(getchar()!='\n'); //Clear the buffer
    stack=createStack();
    
    while(1){
        if(current!=NULL){
            push(stack, current); //Push the current node to the stack
            current=current->next_left; //Go the the leftest node
        }
        else {
            if(!isEmpty(stack)){ //If we have nodes in stack
                current=pop(stack);
                    printf("%d ", current->dat);
                //As we've finished the left side, go right
                current=current->next_right;
            }
            else //The stack is empty. No more nodes to print
                return;
        }
    }//EOWhile
}

void print_levels(Node *root){
    Queue * queue=create_queue();
    Node * current;
    while(getchar()!='\n'); //Clear the buffer
    
    if(!root){ //The tree is empty
        printf("The tree is empty. Nothing to print.\n");
        return;
    }
    
    enqueue(queue, root);
    
    while(!q_isEmpty(queue)){
        current=dequeue(queue);
        printf("%d ", current->dat);
        if(current->next_left)
            enqueue(queue, current->next_left);
        if(current->next_right)
            enqueue(queue, current->next_right);
    }
}

Node * build_tree(){
    Node *root;
   // int result;
    int data;
    while(getchar()!='\n'); //Clear the buffer
    printf("Please input numbers to build the tree.\nTo stop the input, press on any letter\n");
    printf("=> ");
    while(scanf_s("%d", &data)==1){
        printf("=> ");
        insert(&root, data);
    }
    if(root)
        printf("A new tree has been created. [%p]\n", root);
    else
        printf("No values were assigned. Tree wasn't created\n");
    return root;
}