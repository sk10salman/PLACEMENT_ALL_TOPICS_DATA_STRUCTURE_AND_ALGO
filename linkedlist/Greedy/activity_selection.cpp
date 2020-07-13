#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool cmp1(const pair<int,int>&a,const pair<int,int>&b)
{
    if(a.second==b.second)
    {
        return a.first>b.first;
    }
    return a.second<b.second;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<pair<int,int>>v(n,{0,0});
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        v[i].first=x;
	    }
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        v[i].second=x;
	    }
	    sort(v.begin(),v.end(),cmp1);
	    int count=1;
	    int s=v[0].second;
	    for(int i=0;i<v.size();i++)
	    {
	        if(s<=v[i].first)
	        {
	            count++;
	            s=v[i].second;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
