#include "cycle.h"

int testCyclic(LinkedList ls)
{
    Node current = ls->head;
    Node prev = NULL;
    Node next;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        if(current == ls->head)
        {
            return 1;
        }
    }
    return 0;
    
}