#include "store.h"

Element createElement(int start, int end)
{
    Element ele = malloc(sizeof(struct element));
    ele->start = start;
    ele->end = end;
    return ele;
}

void push(Stack st, int start, int end)
{
    st->arr[st->top] = createElement(start, end);
    st->top++;
}

Element pop(Stack st)
{
    st->top--;
    Element ele = st->arr[st->top];
    return ele;
}
 int isStackEmpty(Stack st)
 {
     if(st->top==0)
     {
         return 1;
     }
     return 0;
 }