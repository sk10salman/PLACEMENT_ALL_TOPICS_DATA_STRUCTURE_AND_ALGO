#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool cycle(int i,vector<int>adj[],bool visited[],bool stack[])
{
    if(visited[i]==false)
    {
        visited[i]=true;
        stack[i]=true;
         for(auto j=adj[i].begin();j!=adj[i].end();j++)
           {
               if(!visited[*j] && cycle(*j,adj,visited,stack))
                    return true;
               else if(stack[*j]==true)
                  return true;
           }
         
    }
   stack[i]=false;
   return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool visited[V],stack[V];;
    for(int i=0;i<V;i++)
      {
          visited[i]=false;
          stack[i]=false;
      }
      for(int i=0;i<V;i++)
        {
            if(cycle(i,adj,visited,stack))
              return true;
        }
        return false;
    
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
