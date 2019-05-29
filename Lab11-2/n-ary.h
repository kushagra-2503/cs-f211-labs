#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* Node;
struct node{
    char str[20];
    Node sibling;
    Node child;
    int isLeaf:2;
};

typedef struct tree* Tree;
struct tree{
    Node root;
    int num_elements;
};

Tree createTree();

Node createNode();

void strrev(char* str);

void add(Tree t, char* str, char* ip);

Node insert(Node parent, char str[]);

Node find(Node parent, char str[]);

void lookup(Tree t, char str[]);

int global;