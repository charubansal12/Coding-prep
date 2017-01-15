#include<bits/stdc++.h>
using  namespace std;
vector <int> frames(8);
vector <int> fr;
void initialise()
{
	
	for(int i=0;i<frames.size();i++)
	{
		frames[i]=-1;
	}
	for(int i=0;i<fr.size();i++)
		fr[i]=-1;
}
bool fnd(int pno)
{
	if(fr.size()<3)
		return false;
	for(int i=0;i<3;i++)
	{
		if(fr[i]==pno)
			return true;
	}
	return false;
}
bool isEmpty()
{
	return (fr.size()<3);
	
}
int ret_most_used()
{
	int retno=0;
	int max=frames[fr[0]];
	for(int i=1;i<3;i++)
	{
		if(frames[fr[i]] > max)
		{
			max=frames[fr[i]];
			retno=i;
		}
	}
	return retno;
}
void repl(int a,int b)
{
	fr[a]=b;
}
void display(vector<int>&vec)
{
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
}
int main()
{
	initialise();
	vector <int> preq;
	int x;
	for(int i=0;i<20;i++)
	{
		cin>>x;
		preq.push_back(x);
	}
	int pf=0;
	bool found,emp;
	int j;
	for(int i=0;i<20;i++)
	{
		found=fnd(preq[i]);
		if(found==false)
		{
			pf++;
			frames[preq[i]]++;
			emp=isEmpty();
			if(emp)
				fr.push_back(preq[i]);
			else
			{
				j=ret_most_used();
				repl(j,preq[i]);
			}
		}
		else
		{
			frames[preq[i]]++;
		}
		display(fr);
			cout<<"\n"; 
	}
	cout<<pf<<"\n";
	return 0;
}
