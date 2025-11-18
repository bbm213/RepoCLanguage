#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>

struct Node {
    int data;
    struct Node* next;
}*first = NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while (p!=NULL)
    {
        printf("%d",p->data);
        p=p->next; 
    }
    
}

struct Node * searching(struct Node *p, int key)
{
while (p!=NULL)
{
    if (key==p->data)
    {
        return p;
    }    
    p=p->next;
}
    return NULL;
}

struct Node * Rsearching(struct Node *p, int key)
{
    if (p==NULL)
        return NULL;
    if (key==p->data)
        return p;    
    
    return Rsearching(p->next,key);
        
}

int maximum(struct Node* p) 
{
    int max = INT32_MIN;
    while (p) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int Rmax (struct Node * p)
{
    int x=0 ;
    if (p==0)
        return INT32_MIN;
    x=Rmax(p->next);
    if(x>p->data)
    {
        return x;
    }else
    {
        return p->data;
    }
}

int count (struct Node *p)
{
    int l=0;
    while (p!=NULL)
    {
        l++;
        p=p->next;
    }
    return l;
}

void Insert(struct Node *p, int index, int value)
{
    struct Node *t;
    int i;
    if (index<0 || index> count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=value;

    if (index==0)
    {
        t->next = first;
        first=t;
    }
    else
    {
        for ( i = 0; i < index-1; i++)
            p=p->next;
        t->next=p->next;
        p->next=t;   
    }
}


int main() {
    struct Node *temp;
    int A[] = {1, 2, 3, 6, 5};
    create(A, 5);
     
    Insert(first,0,0);
    Display(first);
    
    printf("Maximum Element: %d\n", maximum(first));
    temp= searching(first,4);
    if (temp!=NULL)
        printf("Key is FOund %d",temp->data);
    else
        printf("Key is not Found");
        
    return 0;
}