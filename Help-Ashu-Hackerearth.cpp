#include<bits/stdc++.h>
using namespace std;
long long arr[100005];
vector<pair<int,int> >tree(300000);
void build(long long node,int a,long long b)
{
    if(a==b)
    {
        if(1&arr[a])
        {
            tree[node].first=1;
            tree[node].second=0;
        }
        else
        {
            tree[node].first=0;
            tree[node].second=1;
        }
    }
    else
    {
        long long mid=(a+b)/2;
        build(2*node,a,mid);
        build(2*node+1,mid+1,b);
        tree[node].first=tree[2*node].first + tree[2*node+1].first;
        tree[node].second=tree[2*node].second+tree[2*node+1].second;
    }
}
void update(long long node,int a,int b,long long idx,long long val)
{
    if(a==b)
    {
        if(val%2!=0 && arr[idx]%2!=0)
        {
            arr[idx]=val;
            tree[node].first=1;
            tree[node].second=0;
        }
        else if(val%2==0 && arr[idx]%2==0)
        {
            arr[idx]=val;
            tree[node].second=1;
            tree[node].first=0;
        }
        else if(val%2!=0 && arr[idx]%2==0)
        {
            tree[node].second=0;
            arr[idx]=val;
            tree[node].first=1;
        }
        else if(val%2==0 && arr[idx]%2!=0)
        {
            tree[node].second=1;
            arr[idx]=val;
            tree[node].first=0;
        }
    }
    else
    {
        long long mid=(a+b)/2;
        if(a<=idx && idx<=mid)
            update(2*node,a,mid,idx,val);
        else
            update(2*node+1,mid+1,b,idx,val);
 
        tree[node].first=tree[2*node].first+tree[2*node+1].first;
        tree[node].second=tree[2*node].second+tree[2*node+1].second;
 
    }
}
long long query(long long node,int a,int b,int q,int l,long long r)
{
    if(a>r || b<l || a>b)
        return 0;
    if(l<=a && b<=r)
    {
        if(q==1)
            return tree[node].second;
        else
            return tree[node].first;
    }
    long long mid=(a+b)/2;
    long long p1=query(2*node,a,mid,q,l,r);
    long long p2=query(2*node+1,mid+1,b,q,l,r);
    return (p1+p2);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    build(1,1,n);
    int q;
    cin>>q;
    while(q--)
    {
        long long q1,x;
        long long y;
        cin>>q1>>x>>y;
        if(q1==0)
            update(1,1,n,x,y);
        else if(q1==1 || q1==2)
        {
            long long ans=query(1,1,n,q1,x,y);
            cout<<ans<<"\n";
        }
 
    }
    return 0;
}
