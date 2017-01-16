#include<bits/stdc++.h>
using namespace std;
#define R 6
#define C 5
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
void getmax(int S[R][C],int &r,int &c,int &maxs)
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(S[i][j] > maxs)
			{
				maxs=S[i][j];
				r=i;
				c=j;
			}
		}
	}
}
void printSol(bool M[R][C],int maxs,int r,int c)
{
	for(int i=r-maxs+1;i<=r;i++)
	{
		for(int j=c-maxs+1;j<=c;j++)
			cout<<M[i][j]<<" ";
		cout<<"\n";
	}
}
void printAns(bool M[R][C])
{
	int S[R][C];
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
			S[i][j]=0;
	}
	for(int i=0;i<R;i++)
		S[i][0]=M[i][0];
	for(int i=0;i<C;i++)
		S[0][i]=M[0][i];
	
	for(int i=1;i<R;i++)
	{
		for(int j=1;j<C;j++)
		{
			if(M[i][j]==1)
			{
				S[i][j]=min(S[i-1][j],min(S[i][j-1],S[i-1][j-1]))+1;
			}
			else
				S[i][j]=0;
		}
	}
	int maxs=-1;
	int r=0,c=0;
	getmax(S,r,c,maxs);
	printSol(M,maxs,r,c);
}
int main()
{
  bool M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
                
  printAns(M);
 
}  
