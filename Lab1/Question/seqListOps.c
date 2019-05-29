/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{

//Implement this function
//
    if(sl.size==-1)
    {
        /*if the list is initially empty*/
        st[sl.head].ele = j;
        sl.size++;
        st[sl.head].next = -1;
        return sl;
    }
    if(st[sl.head].ele.pri>j.pri)
    {
        /*If element is to be inserted before the head*/
        st[nextfreeloc].ele= j;
        st[nextfreeloc].next = sl.head;
        sl.head = nextfreeloc;
        nextfreeloc++;
        sl.size++;
        return sl;
    }
    st[nextfreeloc].ele = j;
    st[nextfreeloc].next = -1;
    int i = sl.head;
    int prev;
    while(compare(st[i].ele.pri, j.pri)==LESSER && i !=-1){
        prev = i;
        i = st[i].next;
    }
    st[nextfreeloc].next = i;
    st[prev].next = nextfreeloc;
    sl.size++;
    nextfreeloc++;
    return sl;
}
  
void insertelements (JobList list , int size, SeqList s[3])
{

// Implement this function
    for(int i =0;i<3;i++)
    {
        s[i]=  createlist();
    }
    for(int i=0;i<MAX;i++)
    {
        if(list[i].pri==0)
        {
            s[0] = insert(list[i], s[0]);
        }
        else if (list[i].pri==1)
        {
            s[1] = insert(list[i], s[1]);
        }
        else
        {
            s[2] = insert(list[i], s[2]);
        }
        
    }

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

// Implement this function
    SeqList sl =s[2];
    int i = sl.head;
    int j=0;
    while(i!=-1){
        ele[j] = st[i].ele;
        i = st[i].next;
        j++;
    }
    SeqList sl =s[1];
     i = sl.head;
    //int j=0;
    while(i!=-1){
        ele[j] = st[i].ele;
        i = st[i].next;
        j++;
    }
    SeqList sl =s[0];
     i = sl.head;
    //int j=0;
    while(i!=-1){
        ele[j] = st[i].ele;
        i = st[i].next;
        j++;
    }
    

}

void printlist(SeqList sl)
{

// Implement this function
    int i = sl.head;
    while(i!=-1){
        printJob(st[i].ele);
        i = st[i].next;
    }
    

}

void printJobList(JobList list, int size)
{

// Implement this function
    for(int j = 0; j < size; j++)
    {
        printJob(j);
    }

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
