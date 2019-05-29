#include "n-ary.h"

Tree createTree()
{
    Tree t = malloc(sizeof(struct tree));
    t->num_elements = 0;
    t->root = createNode();
    return t;
}

Node createNode()
{
    Node n = malloc(sizeof(struct node));
    n->child =NULL;
    n->sibling=NULL;
    n->isLeaf = 0;
}

void strrev(char* str)
{
    int i =  0; 
    int j = strlen(str)-1;
    while(i<j){
        str[i]^=str[j];
        str[j]^=str[i];
        str[i]^=str[j];
        i++;
        j--;
    }   
}

Node find(Node parent, char str[])
{
   
    global = 0;
    Node temp = parent->child;
    while(temp){
        if(strcmp(temp->str, str)==0)
        {
            return temp;
        }
        global++;
        temp = temp->sibling;
    }
   
    return NULL;   
}

Node insert(Node parent, char str[])
{
    Node n = find(parent, str);
    Node temp;
    if(n==NULL)
    {
        n =createNode();
        strcpy(n->str, str);
        temp = parent->child;
        parent->child = n;
        n->sibling = temp;
    }
    return n;
}

void add(Tree t, char* dom, char* ip)
{
    Node parent = t->root;
    char* str = malloc(sizeof(char)*10);
    int j = strlen(dom)-1;
    int i = 0;
    while(j>=0){
        while(dom[j]!='.')
        {
            str[i] = dom[j];
            j--;
            i++;
        }
        
        i = 0;
        j--;
        strrev(str);
        
        parent = insert(parent, str);
    }
    parent = insert(parent, ip);
    parent->isLeaf = 1;
}

void lookup(Tree t, char str[])
{
    int* trace = malloc(sizeof(int)*10); //To be printed if ip is not found.
    int j = strlen(str)-1;
    int i = 0;
    Node parent = t->root;
    char* temp = malloc(sizeof(char)*50);
    int k =0;
    while(j>=0){
        while(str[j] != '.'){
            temp[i] = str[j];
            j--;
            i++;
        }
        i = 0;
        j--;
        strrev(temp);
        parent = find(parent, temp);
        if(parent == NULL)
        {
            break;
        }
        trace[k++] = global;
    }
    if(!parent)
    {
        for(int i = 0; i < k; i++)
        {
            printf("%d\t", trace[i]);
        }
        printf("\n");
    }
    else{
    parent = parent->child;
    if(parent->isLeaf==1)
    {
        printf("%s\n", parent->str);
    }
    else
    {
        for(int i = 0; i < k; i++)
        {
            printf("%d\t", trace[i]);
        }
        printf("\n");
    }
    }
}

void readData(FILE* fp, Tree t, int n)
{
    int i = 0;
    char dom[50];
    char ip[30];
    while(i < n){
        fscanf(fp, "%s%s\n", dom, ip);
        i++;
        add(t, dom, ip);
    }
    
}

int main()
{
    Tree tree = createTree();
    FILE* fp =  fopen("input.txt", "r");
    int choice,n;
    fscanf(fp, "%d%d\n",&choice, &n);
    if(choice==1)
    {
        readData(fp, tree, n);
    }
    fscanf(fp, "%d", &choice);
    char dom[50];
    if(choice==2)
    {
        fscanf(fp,"%s\n", dom);
        lookup(tree,dom);
    }
}