#include <stdio.h>

struct node{
    int element;
    struct node* next;
};
struct linked_list
{
    int count;
    struct node* first;
};
void insertFirst(struct linked_list* head, int ele);
struct node* deleteFirst(struct linked_list* head);
void printList(struct linked_list* head);
int search(struct linked_list* head, int ele);
struct node* delete(struct linked_list* head, int ele);
