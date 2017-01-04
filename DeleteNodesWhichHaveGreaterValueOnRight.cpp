#include<iostream>
#include<stdlib.h>
#include<stack>
#include<stdio.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
stack <node *> st;
void push(node **head,int data)
{
    node *temp=new node;
    temp->data=data;
    temp->next=(*head);
    (*head)=temp;
}
void deleteNodesOnRight(node *head)
{
	node *curr=head->next;
	node *prev=head;
	while(curr->next!=NULL|| curr!=NULL)
	{
		
		if(prev->data < curr->data)
		{
			st.push(curr);
			prev=curr->next;
			if(curr->next==NULL)
			break;
			curr=curr->next->next;
		}
	
	}
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

int main()
{
    node* head = NULL;

     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);

     printf("\nGiven linked list \n");
     printList(head);
     deleteNodesOnRight(head);
     cout<<"\n";
     head=NULL;
	 while(!st.empty())
	 {
	 	//cout<<st.top()->data<<" ";
	 	push(&head,st.top()->data);
	 	st.pop();
	 }
     printList(head);
     return(0);
}


