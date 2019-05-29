#include "cycle.h"

int testCyclic(LinkedList ls)
{//Use hare and tortoise algorithm.
    Node hare = ls->head;
    Node tort = ls->head;
    while(hare && tort && hare->next){
        hare = hare->next->next;
        tort = tort->next;
        if(hare == tort)
        {
            return 1;
        }
    }
    return 0;
}