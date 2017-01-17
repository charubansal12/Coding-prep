#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	vector <string> vec;
	cin>>str;
	int n=str.length();
	string temp=str; 
	for(int i=0;i<n;i++)
	{
		temp=str;
		rotate(temp.begin(),temp.begin()+i,temp.end());
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end());
	cout<<vec[0]<" ";
	return 0;
}
