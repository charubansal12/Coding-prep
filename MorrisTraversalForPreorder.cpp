#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
node *newNode(int data)
{
    node *temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void preorder(node *root)
{
    node *curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else
        {
            node *pred=curr->left;
            while(pred->right!=curr && pred->right!=NULL)
                pred=pred->right;
            if(pred->right==NULL)
            {
                pred->right=curr;
                cout<<curr->data<<" ";
                curr=curr->left;
            }
            else
            {
                pred->right=NULL;
                curr=curr->right;
            }
        }
    }
}
int main()
{
    node *root=newNode(1);
    root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  preorder(root);
  return 0;
}
