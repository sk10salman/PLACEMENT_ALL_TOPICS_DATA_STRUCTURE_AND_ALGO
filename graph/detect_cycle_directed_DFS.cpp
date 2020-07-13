
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool check_cycle(int u,vector<int>adj[],bool visited[],bool current[])
{ //myfuncton
     
   if(current[u]==true)
       return true;
    if(visited[u]==true)
       return false;
     visited[u]=true;
     current[u]=true;
     for(auto i:adj[u])
     {
        
         if(check_cycle(i,adj,visited,current))
            return true;
         
         
     }
     current[u]=false;
     return false;
     
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
   
       bool visit[V];
        bool current[V];
        for(int i=0;i<V;i++)
        {
            visit[i]=false;
            current[i]=false;
        }
    for(int i=0;i<V;i++)
    {
        if(check_cycle(i,adj,visit,current))
           return true;
    }
        return false;
    
}
