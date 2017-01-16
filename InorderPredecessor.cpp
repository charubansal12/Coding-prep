#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *find(node *root,int data)
{
    if(root==NULL)  return  NULL;
    else if(root-> data == data) return root;
    else if(root->data < data)   return find(root->right,data);
    else if(root->data > data)  return find(root->left,data);
}
node *findMax(node *root)
{
    if(root==NULL)
        return NULL;
    node *curr=root;
    while(curr->right!=NULL)
        curr=curr->right;
    return curr;
}
node *getpredecessor(node *root,int data)
{
    if(root==NULL)
        return NULL;
    node *curr=find(root,data);
    if(curr==NULL)
        return NULL;
    if(curr->left!=NULL)
        return findMax(curr->left);
    else
    {
        node *pred=NULL;
        node *anc=root;
        while(anc!=curr)
        {
            if(anc->data > curr->data)
            {
                anc=anc->left;
               // pred=anc;
            }
            else
             {
                 pred=anc;
                  anc=anc->right;
             }
        }
        return pred;
    }
}
void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node *insert(node *root,int data)
{
    if(root==NULL)
    {
        root=new node;
        root->data=data;
        root->left=NULL;
        root->right=NULL;
    }
    else if(data <= root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    return root;
}
int main()
{
    node *root=NULL;
   root = insert(root,5); root = insert(root,10);
	root = insert(root,3); root = insert(root,4);
	root = insert(root,1);
	root = insert(root,11);

    cout<<"Inorder traversal : ";
    inorder(root);
    cout<<"\n";

    node *predecessor=getpredecessor(root,11);
    if(predecessor==NULL)
        cout<<"No predecessor found\n";
    else
        cout<<"Predecessor is : "<<predecessor->data<<"\n";
    return 0;
}
