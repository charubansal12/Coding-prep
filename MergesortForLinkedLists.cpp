#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
void push(node **head,int data)
{
    node *temp=new node;
    temp->data=data;
    temp->next=(*head);
    (*head)=temp;
}
void printList(node *head)
{
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
int getCount(node *head1)
{
    int cnt=0;
    node *curr=head1;
    while(curr!=NULL)
    {
        cnt++;
        curr=curr->next;
    }
    return cnt;
}
node *mergeList(node *head1,node *head2)
{
    node *res=NULL;
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;
	if(head1->data > head2->data)
	{
	    res=head2;
        res->next=mergeList(head1,head2->next);
    }
	else
	{
	    res=head1;
		res->next=mergeList(head1->next,head2);
	}
	return res;
}
node *mergesort(node *a)
{
    node *oldhead=a;
    int mid=getCount(a)/2;

    if(a->next==NULL)
        return a;

   while((mid-1)>0)
   {
       oldhead=oldhead->next;
       mid--;
   }
   node *newHead=oldhead->next;
   oldhead->next=NULL;
   oldhead=a;

   node *l1=mergesort(oldhead);
   node *l2=mergesort(newHead);
   return mergeList(l1,l2);
}
int main()
{
    node *head1=NULL;
    node *res=NULL;
    push(&head1,15);
    push(&head1,10);
    push(&head1,5);
    push(&head1,20);
    push(&head1,3);
    push(&head1,2);

    res=mergesort(head1);
    printList(res);
    return 0;
}
