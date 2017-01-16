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
    if(root==NULL)
        return NULL;
    else if(root->data == data) return root;
    else if(root->data < data) return find(root->right,data);
    else if(root->data > data)  return find(root->left,data);
}
node *findMin(node *root)
{
    if(root==NULL)  return NULL;
    node *curr=root;
    while(curr->left!=NULL)
        curr=curr->left;
    return curr;
}
node *getsuccessor(node *root,int data)
{
    node *curr=find(root,data);
    if(curr==NULL)
        return NULL;
    if(curr->right!=NULL)
        return findMin(curr->right);
    else
    {
        node *ancestor=root;
        node *successor=NULL;
        while(ancestor!=curr)
        {
            if(ancestor->data > curr->data)
            {
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else
            {
                ancestor=ancestor->right;
            }
        }
        return successor;
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
        root->left=NULL;
        root->right=NULL;
        root->data=data;
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
    root=insert(root,5);
    root=insert(root,10);
    root = insert(root,3); root = insert(root,4);
	root = insert(root,1); root = insert(root,11);

    cout<<"Inorder traversal : ";
    inorder(root);
    cout<<"\n";

    node *successor=getsuccessor(root,1);
    if(successor==NULL)
        cout<<"No successor found\n";
    else
        cout<<"Successor is : "<<successor->data<<"\n";
    return 0;

}
