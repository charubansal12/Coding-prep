#include<bits/stdc++.h>
using namespace std;

vector < pair <string,int>  > vec;
vector <string> arr;
int main()
{
    int n;
    cin>>n;
    string str;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        vec.push_back(make_pair(str,i));
        arr.push_back(str);
    }

    for(int i=0;i<vec.size();i++)
    {
        sort(vec[i].first.begin(),vec[i].first.end());
    }
    sort(vec.begin(),vec.end());
    vector <string> ans;
    for(int i=0;i<vec.size();i++)
    {
        ans.push_back(arr[vec[i].second]);
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
