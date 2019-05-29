#include "myalloc.h"

void* myalloc(int size)
{
    int* ptr  = malloc(size+sizeof(int));
    heap_size += size;
    *ptr = size;
    return (void*) ptr +sizeof(int);
}

void myfree(void* ptr)
{
    int* toread = ptr-sizeof(int);
    int size = *toread;
    free(toread);
    heap_size-=size;
}