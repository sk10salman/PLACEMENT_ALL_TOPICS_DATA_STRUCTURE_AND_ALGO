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
	    vector<int> adj[V];
	    for(int i=0;i<E;i++)
	    {
	        int v,u;
	        cin>>v>>u;
	        adj[v].push_back(u);
    adj[u].push_back(v);
	    }
	    for(int i=0;i<V;i++)
     {
         cout<<i;
         for(auto x:adj[i])
         cout<<"-> "<<x;
         cout<<endl;
     }
	    
	}
	return 0;
}
