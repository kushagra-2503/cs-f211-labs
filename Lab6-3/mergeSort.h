#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record{
    char name[20];
    float cgpa;
};
typedef struct record* Element;

void merge(Element Ls1[],int sz1, Element Ls2[],int sz2, Element Ls[]);
void mergeSortRecursive(Element Ls[], int l, int r);
void mergeSortIterative(Element Ls[], int size);
Element* storeRecords(char* filename, int size);
FILE* openFile(char* filename, char* mode);
int min(int x, int y);
