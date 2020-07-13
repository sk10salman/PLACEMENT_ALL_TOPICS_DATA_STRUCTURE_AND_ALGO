
/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool has_cycle(int u,vector<int> g[],bool vis[],int parent)
{
    vis[u]=true;
    for(auto i=g[u].begin();i!=g[u].end();i++)
    {
        if(vis[*i]==false)
        {
            if(has_cycle(*i,g,vis,u))
             return true;
        }
        else if(*i!=parent)
           return true;
    }
  
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   bool *visit= new bool[V];
   for(int i=0;i<V;i++)
     visit[i]=false;
   for(int i=0;i<V;i++)
    {  
         if(visit[i]==false&&has_cycle(i,g,visit,-1))
        return true;
          
    }
    return false;
   
}
