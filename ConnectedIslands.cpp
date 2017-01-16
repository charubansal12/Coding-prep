#include<bits/stdc++.h>
using namespace std;
#define R 5
#define C 5
bool visited[R][C];
void initialise()
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
            visited[i][j]=false;
    }
}
int x[]={1,1,1,0,-1,-1,-1,0};
int y[]={1,0,-1,-1,-1,0,1,1};
void dfs(int mat[R][C],int i,int j)
{
  // int cnt=0;
   stack<pair<int,int> > st;
   st.push(make_pair(i,j));
   while(!st.empty())
   {
       pair<int,int> temp=st.top();
       st.pop();
       if(visited[temp.first][temp.second]==0 && mat[temp.first][temp.second]==1)
       {
           visited[temp.first][temp.second]=1;
           for(int i=0;i<8;i++)
           {
               if(temp.first+x[i]>=0 && temp.first+x[i] < R && temp.second+y[i]>=0 && temp.second+y[i]<C){
                    if(visited[temp.first + x[i]][temp.second+y[i]]==false && mat[temp.first + x[i]][temp.second+y[i]]==1)
                        st.push(make_pair(temp.first + x[i],temp.second+y[i]));

               }
           }
       }
   }
}
int main()
{
    initialise();
    int mat[][C]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
    int cnt=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(visited[i][j]==false && mat[i][j]==1)
            {
                dfs(mat,i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<" ";
}
