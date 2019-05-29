#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee{
    char name[11];
    int empId;
};
typedef struct employee* Employee;

struct element{
    int start;
    int end;
};
typedef struct element* Element;

struct stack{
    Element arr[1000];
    int top;
};
typedef struct stack* Stack;

Employee* readData(char* filename, int size);
FILE* openFile(char* filename, char* mode);


void push(Stack st, int start, int end);
Element createElement(int start, int end);
Element pop(Stack st);
int isStackEmpty(Stack st);

void quickSortIterative(Employee* arr, int size);
int partition(Employee* arr,int start, int end);