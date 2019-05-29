#include "insertionSort.h"

int main()
{
    int asd;
    Card* arr = storeRecords("1000", 20);
    insertionSort(arr, 1000);
   for(int  i = 0; i < 999; i++)
   {
       if(arr[i]->num > arr[i+1]->num)
       {
           printf("error\n");
       }
   }
}