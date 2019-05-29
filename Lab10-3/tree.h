#include <stdio.h>
#include <stdlib.h>

typedef struct node* Node;
struct node{
    int key;
    Node left;
    Node right;
    int hb;
};

Node rotate(Node bt, Node x, Node y, Node z);

Node add(Node bt, int key);

int height(Node bt);

void inOrder(Node bt);

Node delete_assist(Node bt, int key);

Node treeMin(Node bt);

Node inOrderSucc(Node bt, Node n);

void preOrder(Node bt);