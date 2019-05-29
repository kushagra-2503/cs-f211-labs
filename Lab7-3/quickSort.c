#include "store.h"

FILE* openFile(char* filename, char* mode)
{
    FILE* fp = fopen(filename, mode);
    if(fp==NULL)
    {
        printf("Error\n");
        exit(1);
    }
    return fp;
}

Employee* readData(char* filename, int size)
{
    FILE* fp = openFile(filename, "r");
    Employee* arr = malloc(sizeof(struct employee)*size);
    for(int i=0;i<size;i++)
    {
        arr[i] = malloc(sizeof(struct employee));
    }
    int num_records = 0;
    char name[11];
    int empId;
    while(fscanf(fp, "%s%d",name, &empId)!=EOF){
        strcpy(arr[num_records]->name, name);
        arr[num_records]->empId = empId;
        num_records++;
    }
    return arr;
}

int partition(Employee* arr, int start,  int end)
{
    Employee pivot = arr[end];
    int i = start-1;
    int j = start;
    Employee temp;
    while(j < end){
        if(arr[j]->empId <= pivot->empId)
        {
            i = i+1;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return i+1;
}

void quickSortIterative(Employee* arr, int size)
{
    Stack st = malloc(sizeof(struct stack));
    push(st, 0, size-1);
    while(!isStackEmpty(st)){
        Element ele = pop(st);
        int start = ele->start;
        int end = ele->end;
        if(start >= end)
        {
            continue;
        }
        int pivot = partition(arr, start, end);
        push(st,start, pivot-1);
        push(st, pivot+1, end);
    }
}

void quickSortRecursive(Employee* arr, int start, int end)
{
    if(start<=end)
    {
        int pivot = partition(arr, start, end);
        quickSortRecursive(arr, start, pivot-1);
        quickSortRecursive(arr, pivot+1, end);
    }
}

int main()
{
    Employee* arr = readData("100000", 100000);
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]->empId);
    }
    quickSortRecursive(arr, 0,100000-1);
    printf("sorted:\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%s\n", arr[i]->name);
    }
}