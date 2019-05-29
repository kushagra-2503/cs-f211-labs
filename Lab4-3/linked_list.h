#include "myalloc.h"
#include <time.h>
struct node{
    int key;
    struct node* next;
};
typedef struct node* Node;

struct linked_list{
    Node head;
    int length;
};
typedef struct linked_list* LinkedList;

LinkedList createList(int n);
void createCycle(LinkedList ls);
void insert(LinkedList ls, int key);
Node createNode(int key);
