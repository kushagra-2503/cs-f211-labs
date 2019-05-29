#include "tree.h"

int main()
{
    Node bt = malloc(sizeof(struct node));
    bt->key = 3;
    bt->left = bt->right = NULL ;
    bt->hb =0;
    bt = add(bt, 2);
    bt = add(bt, 1);
    bt = add(bt, 4);
    bt = add(bt, 5);
    bt = add(bt, 6);
    bt = add(bt, 7);
    bt = add(bt, 16);
    bt = add(bt, 15);
    bt = add(bt, 14);
    bt = add(bt, 13);
    bt = add(bt, 12);
    bt = add(bt,11);
    bt = add(bt,10);
    preOrder(bt);
}