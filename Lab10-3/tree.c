#include "tree.h"

int height(Node bt)
{
    if(bt == NULL)
    {
        return -1;
    }
    int left_height = height(bt->left);
    int right_height = height(bt->right);
    return left_height > right_height ? left_height+1 : right_height+1;
}

Node add(Node bt, int key)
{
    if(bt == NULL)
    {
        Node n = malloc(sizeof(struct node));
        n->hb = 0;
        n->key = key;
        n->left =n->right = NULL;
        return n;
    }
    else if (bt->key > key)
    {
        bt->left = add(bt->left, key);
    }
    else if(bt->key < key )
    {
        bt->right = add(bt->right, key);
    }
    else
    {
        return bt;
    }

     bt->hb= height(bt->right) - height(bt->left);

    if(bt->hb > 1 && bt->right->key < key)
    {
        bt =  rotate(bt, bt->right->right, bt->right, bt);
    }
    else if (bt->hb > 1 && bt->right->key > key)
    {
        bt =  rotate(bt, bt->right->left, bt->right, bt);
    }
    else if (bt->hb < -1 && bt->left->key > key)
    {
        bt = rotate(bt, bt->left->left, bt->left, bt);
    }
    else if (bt->hb < -1 && bt->left->key < key)
    {
        bt =  rotate(bt, bt->left->right, bt->left, bt);
    }
    bt->hb = height(bt->right) - height(bt->left);
    return bt;      
}


Node rotate(Node bt, Node x, Node y, Node z)
{
    Node a,b,c,t0,t1,t2,t3;
    if(y==z->left)
    {
        c = z;
        t3 = z->right;
        if(x == y->left)
        {
            a = x;
            b = y;
            t0 = x->left;
            t1 = x->right;
            t2 = y->right;
        }
        else if( x== y->right)
        {
            a = y;
            b = x;
            t0 = y->left;
            t1 = x->left;
            t2=  x->right;
        }
    }
    else if(y==z->right)
    {
        a = z;
        t0 = z->left;
        if(x== y->right)
        {
            c = x;
            b = y;
            t1= y->left;
            t2 = x->left;
            t3 = x->right;
        }
        else if( x==y->left)
        {
            b = x;
            c = y;
            t1 = x->left;
            t2 = x->right;
            t3 = y->right;
        }    
    }

    bt = b;
    b->left = a;
    b->right = c;
    a->left = t0;
    a->right = t1;
    c->left = t2;
    c->right = t3;
    int h0 = height(t0);
    int h1 = height(t1);
    int h2 = height(t2);
    int h3 = height(t3);
    a->hb = h1 - h0;
    c->hb = h3 - h2;
    b->hb = height(c) - height(a);
    return bt;
}


void inOrder(Node bt)
{
    if(bt)
    {
       inOrder(bt->left);
       printf("%d\n", bt->key);
       inOrder(bt->right);
    }
}

void preOrder(Node bt)
{
    if(bt)
    {
        printf("%d\n", bt->key);
        preOrder(bt->left);
        preOrder(bt->right);
    }
}

Node find(Node bt, int key)
{
    if(bt == NULL || bt->key ==key)
    {
        return bt;
    }
    if(bt->key > key)
    {
        return find(bt->left, key);
    }
    if(bt->key < key)
    {
        return find(bt->right, key);
    }
}


Node delete_assist(Node bt, int key)
{
    if(bt==NULL)
    {
        return NULL;
    }
    if(bt->key > key)
    {
        bt->left = delete_assist(bt->left, key);
    }
    else if (bt->key < key)
    {
        bt->right = delete_assist(bt->right, key);
    }
    else
    {
        if(bt->left == NULL)
        {
            Node temp = bt->right;
            free(bt);
            return temp;
        }
        else if (bt->right ==NULL)
        {
            Node temp = bt->left;
            free(bt);
            return temp;
        }
        else
        {
            Node temp = bt->right;
            while(temp->left){
                temp= temp->left;
            }
            bt->key = temp->key;
            bt->right = delete_assist(bt->right, temp->key);
        }
    }
    if(bt == NULL)
    {
        return bt;
    }
    bt->hb = height(bt->right) - height(bt->left);
    if(bt->hb > 1 && bt->right->key < key)
    {
        bt = rotate(bt, bt->right->right, bt->right, bt);
    }
    else if (bt->hb < -1 && bt->left->key > key)
    {
        bt = rotate(bt, bt->left->left, bt->left, bt);
    }
    else if (bt->hb > 1 && bt->right->key > key)
    {
        bt = rotate(bt, bt->right->left, bt->right, bt);
    }
    else if (bt->hb < -1 && bt->left->key < key)
    {
        bt = rotate(bt, bt->left->right, bt->left, bt);
    }
    bt->hb = height(bt->right)  -height(bt->left);
    return bt;
}

Node treeMin(Node bt)
{
    Node temp = bt;
    while(temp->left){
        temp = temp->left;
    }
    return temp;    
}