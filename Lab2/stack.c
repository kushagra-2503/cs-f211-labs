#include <stdio.h>
#include "linked_list.h"
 #include "stack.h"
 int pop(struct linked_list* head)
 {
     struct node* temp = deleteFirst(head);
     return temp->element;
 }

 void push(struct linked_list* head, int ele)
 {
     insertFirst(head, ele);
 }