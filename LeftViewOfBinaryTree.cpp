#include<bits/stdc++.h>
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
int height(node *node)
{
    if(node==NULL)
        return 0;
    int ldep=height(node->left);
    int rdep=height(node->right);
    if(ldep > rdep)
        return ldep+1;
    else
        return rdep+1;
}
void printGivenLevel(node *root,int level,bool &done)
{
    if(done==true || root==NULL || level==0)
        return;
    if(level == 1 && done==false)
    {
        cout<<root->data<<"\n";
        done=true;
        //return;
    }
    else if(level > 1)
    {
        printGivenLevel(root->left,level-1,done);
        printGivenLevel(root->right,level-1,done);
    }
}
void levelorder(node *root)
{
    if(root==NULL)
        return ;
    bool done;
    int ht=height(root);
    for(int d=1;d<=ht;d++)
    {
        done=false;
        printGivenLevel(root,d,done);
        //done=true;
    }
}
int main()
{
    node *root = newNode(12);
    root->left        = newNode(10);
    root->right       = newNode(30);
    root->right->left  = newNode(25);
    root->right->right = newNode(40);
    levelorder(root);
}
