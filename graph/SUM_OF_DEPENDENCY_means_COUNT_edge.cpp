#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int V,E;
	    cin>>V>>E;
	    vector<int>adj[V];
	    for(int i=0;i<E;i++)
	    {
	        int u,v;
	        cin>>u>>v;
	        adj[u].push_back(v);
	    }
	   // cout<<E<<endl;edge count krne hai
	   int count=0;
	   for(x:adj)
	      count += x.size();
	     cout<<count<<endl;
	}
	return 0;
}
