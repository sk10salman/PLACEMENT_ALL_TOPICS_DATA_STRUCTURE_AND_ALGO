#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int BFS(vector<int> adj[],int N)
{
    bool vis[N+1];
    memset(vis,false,sizeof(vis));
    int dis[N+1];
    memset(dis,0,sizeof(dis));
    queue<int>q;
    vis[1]=true;
    q.push(1);
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int x:adj[curr])
        {
            if(!vis[x])
            {
                dis[x]=dis[curr]+1;
                vis[x]=true;
                q.push(x);
            }
        }
    }
    return dis[N];
}
int main()
 {
	//code
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	
	while(t--)
	{
	    int N;
	    cin>>N;
	    vector<int>adj[N+1];
	    for(int i=1;i<=N;i++)
	      for(int j=i;j<=N;j++)
	      {
	          if(j==i+1||j==(3*i))
	            adj[i].push_back(j);
	      }
	    cout<<BFS(adj,N)<<endl;
	}
	return 0;
}

/*
Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.
