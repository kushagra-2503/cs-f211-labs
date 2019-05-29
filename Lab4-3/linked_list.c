#include "linked_list.h"

LinkedList createList(int n)
{
    srand(time(0));
    LinkedList ls = myalloc(sizeof(struct linked_list));
    int key;
    for(int i =  0;  i < n ; i++)
    {
        key = rand();
        insert(ls, key);
    }
    return ls;
}

Node createNode(int key)
{
    Node n = myalloc(sizeof(struct node));
    n->key = key;
    n->next = NULL;
    return n;
}

void insert(LinkedList ls, int key)
{
    Node n = createNode(key);
    Node temp = ls->head;
    ls->head = n;
    n->next = temp;
    ls->length++;
}

void printhead(LinkedList ls)
{
    Node temp = ls->head;
    for(int i = 0 ; i < 10; i++)
    {
        printf("%d\n", temp->key);
        temp = temp->next;
    }
}

void createCycle(LinkedList ls)
{
    srand(time(0));
    int toss = rand();
    if(toss>RAND_MAX/2)
    {
        printf("Not cyclic\n");
        return;
    }
    printf("Cyclic\n");
    int* arr = myalloc(sizeof(int)* ls->length);
    int i = 0;
    Node temp = ls->head;
    while(temp){
        arr[i] = temp->key;
        i++;
        temp = temp->next;
    }
    double r = (double) rand()/RAND_MAX;
    int random = ls->length *r;
    int tocyclekey = arr[random];
    Node tocyclenode = NULL;
    Node traverse = ls->head;
    while(traverse->next){
        if(traverse->key == tocyclekey)
        {
            tocyclenode = traverse;
        }
        traverse = traverse->next;
    }
    traverse->next = tocyclenode;   
}

