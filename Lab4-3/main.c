#include "cycle.h"
void makeCircularList(LinkedList ls)
{
    if(!testCyclic(ls))
    {
        Node temp = ls->head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next  = ls->head;
    }
    else
    {
        Node hare = ls->head;
        Node tort = ls->head;
        while(hare && tort){
            hare=  hare->next->next;
            tort = tort->next;
            if(hare == tort)
            {
                break;
            }
        }
        tort = ls->head;
        int count = 0;
        while(hare!=tort){
            hare = hare->next;
            tort = tort->next;
            count++;
        }
        Node traverse = ls->head;
        Node temp  =NULL;
        for(int i = 0 ; i < count ;i++)
        {
            temp = traverse;
            traverse = traverse->next;
            myfree(temp);
            ls->length--;
        }
        ls->head = traverse;
    }
    
}
int main()
{
    LinkedList ls = createList(5000000);
    createCycle(ls);

    makeCircularList(ls);
    if(testCyclic(ls))
    {
        printf("List is cyclic\n");
    }
    else
    {
        printf("List is not cyclic\n");
    }
}