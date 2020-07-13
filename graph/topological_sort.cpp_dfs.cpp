/*
jo pehle end hoga vo front nai insert hota jaayega 
many posible of topological sort

Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
void topolog(int u,vector<int> adj[],vector<int>&v,bool visit[])
{
    visit[u]=true;
    for(auto i:adj[u])
      {
          if(!visit[i])
            topolog(i,adj,v,visit);
      }
      v.push_back(u);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    vector<int>v;
    
    bool visit[V];
    memset(visit,0,sizeof(visit));
    for(int i=0;i<V;i++)
    {
        if(!visit[i])
          topolog(i,adj,v,visit);
    }
    reverse(v.begin(),v.end());
    return v;
    
}

