#include<iostream>
#include<stdio.h>
#include<algorithm>
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
int findDistance(node *root,int k,int level)
{
    if(root==NULL)
        return -1;
    if(root->data==k)
        return level;
    int l=findDistance(root->left,k,level+1);
    return (l != -1)? l : findDistance(root->right, k, level+1);
}
int find(node *root,int val)
{
    if(root==NULL)
        return 0;
    if(root->data==val)
        return 1;
    return find(root->left,val) || find(root->right,val);
}
node *LCA(node *root,int n1,int n2)
{
    if(!root)
        return NULL;
    if(root->data == n1 || root->data==n2)
        return root;
    node *l1=LCA(root->left,n1,n2);
    node *l2=LCA(root->right,n1,n2);
    if(l1 && l2)
        return root;
    return l1?l1:l2;
}
int lca(node *root,int n1,int n2)
{
    if(root==NULL || !find(root,n1) || !find(root,n2))
        return -1;
    node *ans=LCA(root,n1,n2);
    if(!ans)
        return -1;
    else
        return ans->data;
}
int dist(node *root,int n1,int n2)
{
    int l1=findDistance(root,n1,0);
    int l2=findDistance(root,n2,0);
    if(l1==-1 || l2==-1)
        return -1;
    int leastcommon=lca(root,n1,n2);
    int level=findDistance(root,leastcommon,0);
    return l1+l2-2*level;
}
int main()
{
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    cout << "Dist(4, 5) = " << dist(root, 4, 5);
    cout << "\nDist(4, 6) = " << dist(root, 4, 6);
    cout << "\nDist(3, 4) = " << dist(root, 3, 4);
    cout << "\nDist(2, 4) = " << dist(root, 2, 4);
    cout << "\nDist(8, 5) = " << dist(root, 8, 5);
    return 0;
}

