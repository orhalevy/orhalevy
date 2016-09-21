#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

/*
Node * create_tree(){
    Node * tree=(Node *) malloc(sizeof(Node));
    if(!tree){
        printf("Error! Can't allocate memory for new tree\n");
        exit(1); //Exit with error
    }
    tree->next_left=NULL;
    tree->next_right=NULL;
    return tree;
}
*/


Node * new_node(type dat){
    Node * node = (Node *) malloc(sizeof(Node));
    if(!node){
        printf("Error! Could not allocate memory for new node\n");
        exit(1); //Exit with error
    }
    
    node->dat=dat;
    node->next_left=node->next_right=NULL;
    
    return node;
}

type maxi(type first, type second){
    if(first>second)
        return first;
    return second;
}

int tree_height(Node * root){
    if(!root)
        return -1; //The tree doesn't exist
    return maxi(tree_height(root->next_left), tree_height(root->next_right)) +1;
}

void insert(Node ** root, type dat){
    if(!*root){ //If the tree is empty
        *root=new_node(dat);
        return;
    }
    
    if(dat < (*root)->dat)
        insert(&(*root)->next_left, dat); //Go left
    else
        insert(&(*root)->next_right, dat); //Go right
}

void destroy_tree(Node *leaf){
    if(leaf!=NULL){
        destroy_tree(leaf->next_left);
        destroy_tree(leaf->next_right);
        printf("Free: %p [%d]\n", leaf, leaf->dat);
        free(leaf);
    }
}