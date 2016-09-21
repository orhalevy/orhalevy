#ifndef TREE_H
#define TREE_H

typedef int type;

typedef struct node{
    type dat;
    struct node * next_left;
    struct node * next_right;
}Node;

typedef struct {
    Node * root;
} Root;

int height(Node *); //Calculate the height
Node * new_node(type); //Create a new node
//Node * create_tree(); //Create a new tree
void insert(Node **, int); //Add a new node to a tree
int remove_node(Node *); //Remove an existing node from a tree
Node * find(Node *, type); //Find a node with specific key
Node * free_tree(Node*); //Free the tree
type  maxii(type,type);
int tree_height(Node *); //Get the height of the tree
void print_inorder(Node *); //Print the tree in order
void destroy_tree(Node *);

#endif