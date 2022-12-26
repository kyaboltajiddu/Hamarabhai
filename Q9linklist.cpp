#include<bits/stdc++.h>

using namespace std;

struct node{
int data;
struct node *next;
};

void display(struct node *ptr)
{

    struct node *temp=ptr;

    cout<<endl;

    while(temp!=NULL)
    {
    printf("%d ",temp->data);
    temp=temp->next;
    }
}

void insertBegin(struct node **ptr,int value)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=value;

     if(*ptr==NULL)
    {
        *ptr=p;
        return ;
    }


    p->next=*ptr;
    *ptr=p;
}

void insertEnd(struct node **ptr,int value)
{
    struct node *p;
    struct node *temp=*ptr;

    p=(struct node *)malloc(sizeof(struct node));
    p->data=value;
    p->next=NULL;

    if(*ptr==NULL)
    {
        *ptr=p;
        return ;
    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=p;
    return ;
}

void deleteBegin(struct node *ptr)
{
    struct node *p=ptr->next;
    *ptr=*p;
}

void deleteEnd(struct node **ptr)
{
    struct node *p=*ptr;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    p->next=NULL;

}

void deleteIndex(struct node *head,int index)
{
    struct node *p=head;

    int i=1;
    while(i<index)
    {
        p=p->next;
        i++;
    }

    p->next=p->next->next;
}

int main()
{

    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));

    head->data=15;
    head->next=NULL;

    display(head);
    insertBegin(&head,10);
    insertEnd(&head,105);
    display(head);

    deleteBegin(head);
    display(head);

    insertBegin(&head,20);
    display(head);

    insertEnd(&head,505);
    insertEnd(&head,205);
    insertEnd(&head,305);

    deleteEnd(&head);
    display(head);

    cout<<"\nIndex deletion is here : ";

    deleteIndex(head,2);
    display(head);

    cout<<"\n\n";
    return 0;
}