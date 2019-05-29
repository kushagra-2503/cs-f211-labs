#include "insertionSort.h"
void insertInOrder(Card* arr, Card record, int size)
{
    arr[size] = record;
    int i = size-1;
    while(i >= 0 && arr[i]->num > record->num){
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = record;
}

void insertionSort(Card* arr,int size)
{
    if(size == 1)
    {
            topofstack = &size;
            return;
    }
    insertionSort(arr, size-1);
    insertInOrder(arr, arr[size-1], size-1);
}