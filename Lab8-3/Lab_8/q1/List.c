#include "List.h"

List createList(Student studArray, int arraySize){
    List ls = malloc(sizeof(struct list));
    ls->first = malloc(sizeof(struct node));
    Node temp = ls->first;
    for(int  i= 0 ; i  < arraySize;i++)
    {
        temp->record = myalloc(sizeof(struct student));
        temp->record->name = myalloc(sizeof(char)*11);
        strcpy(temp->record->name, studArray[i].name);
        temp->record->marks = studArray[i].marks;
        if(i==arraySize-1)
        {
            ls->last = temp;
            temp->next = NULL;
            ls->count++;
            break;
        }
        temp->next = myalloc(sizeof(struct node));
        temp = temp->next;
        ls->count++;
    }
    return ls;
}

void insertInOrder(List list, Node newNode)
{
    if(list->first==NULL)
    {
        list->first = myalloc(sizeof(struct node));
        list->count++;
        list->first = list->last = newNode;
        return;
    }
    Node temp  = list->first;
    if(newNode->record->marks <= temp->record->marks)
    {
        list->first = newNode;
        newNode->next = temp;
        list->count++;
        return;
    }
    Node prev = NULL;
    while(temp && newNode->record->marks >= temp->record->marks){
        prev = temp;
        temp = temp->next;
    }
    prev->next = newNode;
    newNode->next = temp;
    list->count++;
    if(!temp)
    {
        list->last = newNode;
    }
}

List insertionSort(List list){
    List sorted = myalloc(sizeof(struct list));
    sorted->count = 0;
    sorted->first = NULL;
    sorted->last = NULL;
    Node temp =  list->first;
    Node prev=  NULL;
    while(temp){
        Node newNode = myalloc(sizeof(struct node));
        newNode->record = myalloc(sizeof(struct student));
        newNode->record->name = myalloc(sizeof(char)*11);
        strcpy(newNode->record->name, temp->record->name);
        newNode->record->marks = temp->record->marks;
        newNode->next = NULL;
        insertInOrder(sorted, newNode);
        temp = temp->next;
    }
    return sorted;
}


double measureSortingTime(List list)
{
    struct timeval t1, t2;
    double elapsedtime;
    gettimeofday(&t1, NULL);
    insertionSort(list);
    gettimeofday(&t2, NULL);
    elapsedtime = 1000.00*(t2.tv_sec - t1.tv_sec);
    elapsedtime+=(t2.tv_usec - t1.tv_usec)/1000;
    return elapsedtime;
}

void * myalloc(int size)
{
    int* ptr = malloc(size+4);
    globalCounter+=size;
    *ptr = size;
    return (void*)ptr + 4;
}

void myfree(void* ptr)
{
    int* toread = ptr-4;
    int size = *toread;
    globalCounter-=size;
    free(toread);
}