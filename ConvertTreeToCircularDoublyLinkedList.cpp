#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
struct lnode
{
    int val;
    lnode *next;
    lnode *prev;
};
stack <int> st;
void push1(lnode **head,int val)
{
    lnode *temp=new lnode;
    
    temp->val=val;
    temp->next=(*head);
    temp->prev=NULL;
    (*head)=temp;
}

node *newNode(int data)
{
    node *temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(node *root)
{
    if(root==NULL)
  		return ;
   inorder(root->left);
   //cout<<root->data<<" ";
   st.push(root->data);
   inorder(root->right);
}
void printStack()
{
   while(!st.empty())
    {
        cout<<st.top()<<"\n";
        st.pop();
    }
}
void printList(lnode *root)
{
    lnode *curr=root;
    do
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }while(curr->next!=root);
}
void printList1(lnode *head)
{
	lnode *curr=head;
	while(curr!=NULL)
	{
		cout<<curr->val<<"\n";
		curr=curr->next;
	}
}
void conv()
{
    
    lnode *res=NULL;
    while(!st.empty())
    {
    	push1(&res,st.top());
    //	cout<<st.top()<<" ";
    	st.pop();
    }
   // printList1(res);
    lnode *curr=res;
    lnode *next1;
    lnode *temp=res;
    while(temp->next!=NULL)
        temp=temp->next;
    curr->prev=temp;
    temp->next=res;
   // printList(res);
    while(next1!=res)
    {
    	next1=curr->next;
      next1->prev=curr;
      curr=next1;
      next1=next1->next;
    }
    printList(res);
}
int main()
{
    node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

	inorder(root);
    conv();
    //
   // printStack();
    return 0;
}
