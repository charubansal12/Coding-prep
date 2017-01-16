#include<bits/stdc++.h>
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
void insert_at_end(node **head,node *temp)
{
    if(head==NULL)
        return ;
    node *curr=*head;
    while(curr->next!=NULL)
        curr=curr->next;
    temp->next=NULL;
    curr->next=temp;
}
void subtract(node *head,int n)
{
    node *curr=head;
    node *temp;
    stack<node *>st;
    stack<node *>st1;
    if(n==1)
        return;
    if(1&n)
        n=n+1;
    for(int i=1;i<n/2;i++)
        curr=curr->next;

    temp=curr->next;
    curr->next=NULL;
    //printList(head);
    while(temp)
    {
        st.push(temp);
        temp=temp->next;
    }
    curr=head;
    while(!st.empty())
    {
        node *temp1=st.top();
        st.pop();
       // cout<<temp1->data<<" ";
        node *temp2=new node;
        temp2->data=(temp1->data - curr->data);
        temp2->next=NULL;
       // cout<<temp2->data<<"\n";
       // temp1->data=(temp1->data-curr->data);
        //cout<<temp1->data<<"\n ";
        curr=curr->next;
        //temp1->next=NULL;
        st1.push(temp2);
    }
    while(!st1.empty())
    {
        node *ptr=st1.top();
        st1.pop();
        insert_at_end(&head,ptr);
    }
    printList(head);
}
int len(node *head)
{
    node *curr=head;
    int cnt=0;
    while(curr)
    {
        curr=curr->next;
        cnt++;
    }
    return cnt;
}
int main()
{
    node *head1=NULL;
    push(&head1,1);
    push(&head1,15);
    push(&head1,11);
    push(&head1,5);
    push(&head1,9);
    push(&head1,3);
    push(&head1,2);
    printList(head1);
    cout<<"\n\n";
    int n=len(head1);
   // cout<<n<<"\n";
    subtract(head1,n);
    return 0;
}
