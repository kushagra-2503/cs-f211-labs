#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(int argc, char* argv[])
{
    FILE* fptr = fopen(argv[1], "r");
    struct  linked_list* head= malloc(sizeof(struct linked_list));
    while(!feof(fptr)){
        int temp;
        fscanf(fptr,"%d ", &temp);
        insertFirst(head,temp);
    }
    fclose(fptr);
    printList(head);
    deleteFirst(head);
    printList(head);
    struct node* temp = head->first;
    FILE * fileptr = fopen("output.txt", "w");
    while(temp){
        fprintf(fileptr,"%d\n", temp->element);
        temp = temp->next;
    }
    
}