#include "mergeSort.h"

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < sz1 && j < sz2){
        if(Ls1[i]->cgpa < Ls2[j]->cgpa){
            Ls[k]  = Ls1[i];
            i++;
            k++;
        }
        else{
            Ls[k] = Ls2[j];
            k++;
            j++;
        }
    }
    while(i < sz1){
        Ls[k] = Ls1[i];
        i++;
        k++;
    }
    while(j  <sz2){
        Ls[k] = Ls2[j];
        j++;
        k++;
    }    
}

void mergeSortRecursive(Element* Ls, int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;
        Element* Ls3 = malloc(sizeof(Element)*(r-l+1));
        int sz1 = m -l+1;
        int sz2 = r-m;
        mergeSortRecursive(Ls,l,m);
        mergeSortRecursive(Ls, m+1, r);
        merge(Ls + l, sz1, Ls+m+1, sz2, Ls3);
        for(int i = 0; i < sz1  +sz2; i++)
        {
            Ls[l + i] = Ls3[i];
        }
    }
}

FILE* openFile(char* filename, char* mode)
{
    FILE* fptr = fopen(filename, mode);
    if(fptr == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    return fptr;
}

Element* storeRecords(char* filename, int size)
{
    FILE* fptr = openFile(filename, "r");
    Element* Ls = malloc(sizeof(Element)*size);
    for(int i =  0 ; i < size; i++)
    {
        Ls[i] = malloc(sizeof(struct record));
    }
    char* name = malloc(sizeof(char)*20);
    float cgpa;
    int i = 0;
    while(fscanf(fptr, "\"%[^,],%f\"q\n", name, &cgpa)!=EOF){
        strcpy(Ls[i]->name, name);
        Ls[i]->cgpa = cgpa;
        i++;
    }
    return Ls;
}


void mergeSortIterative(Element* Ls, int size)
{
    for(int curr_size = 1; curr_size <= size-1 ; curr_size*=2)
    {
        for(int left_start =0 ;left_start < size-1; left_start += 2*curr_size)
        {
           
            int mid = min(left_start+curr_size-1, size-1);
            int right_end = min(left_start+2*curr_size-1, size-1);
            int sz1 = mid - left_start+1;
            int sz2 = right_end-mid;
            Element* Ls3 = malloc(sizeof(Element)*(sz1+sz2));
            merge(Ls+left_start, sz1, Ls+mid+1, sz2, Ls3);
            for(int i = 0 ;i < sz1+sz2;i++)
            {
                Ls[left_start+i] = Ls3[i];
            }
        }
    }
}


int min(int x, int y)
{
    return x > y ? y : x;
}



int main()
{
    Element* arr = storeRecords("1024000.txt", 1024000);
    for(int i = 0 ; i < 10; i++)
    {
        printf("%s\n", arr[i]->name);
    }
    //mergeSortRecursive(arr, 0, 10239);
    mergeSortIterative(arr,1024000);
    for(int i = 0 ; i  < 102399; i++)
    {
        if(arr[i]->cgpa > arr[i+1]->cgpa)
        {
            printf("Error\n");
        }
    }
}