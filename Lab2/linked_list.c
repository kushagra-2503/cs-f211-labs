#include "linked_list.h"
#include <stdlib.h>
void insertFirst(struct linked_list* head, int ele)
{
    struct node* link = (struct node*)malloc(sizeof(struct node));
    link->element = ele;
    link->next = head->first;
    head->first = link;
    head->count++;
}

struct node* deleteFirst(struct linked_list* head)
{
    
    struct node* temp = head->first;
    if(!temp)
    {
        return NULL;
    }
    head->first = temp->next;
    head->count--;
    return temp;
}

void printList(struct linked_list* head)
{
    struct node* temp = head->first;
    while(temp)
    {
            printf("%d ", temp->element);
            temp = temp->next;
    }
    printf("\n");
}

int search(struct linked_list* head, int ele)
{
    struct node* temp = head->first;
    while(temp)
    {
        if(temp->element==ele)
        {
            return 1;
        }
    }
    return 0;
}

struct node* delete(struct linked_list* head, int ele)
{
    struct node* temp = head->first;
    if(temp->element==ele)
    {
        return(deleteFirst(head));
    }
    struct node* prev = temp;
    temp = temp->next;
    while(temp){
        if(temp->element==ele)
        {
            prev->next = temp->next;
            return temp;
        }
        prev = temp;
        temp = temp->next;
    }
    return NULL;
    
}