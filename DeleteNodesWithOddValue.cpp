#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
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
void del(node **head)
{
    node *res=NULL;
    node *cur=*head;
    while(cur!=NULL && ((cur->data)%2!=0))
        cur=cur->next;
    *head=cur;
    if(cur==NULL)
        return;
    res=*head;
    cur=cur->next;
    while(cur!=NULL)
    {
        if(cur->data%2==0)
         {

            res->next=cur;
            res=res->next;
             cur=cur->next;
         }
        else
        {
           //  cout<<cur->data<<" ";
             node  *temp=cur;
             cur=cur->next;
             temp->next=NULL;
             delete(temp);

        }
    }
    res->next=NULL;
}
int main()
{
    node *head1=NULL;
    push(&head1,15);
    push(&head1,11);
    push(&head1,5);
    push(&head1,9);
    push(&head1,3);
    push(&head1,2);
    printList(head1);
    cout<<"\n\n";
    del(&head1);
   printList(head1);
    return 0;
}
