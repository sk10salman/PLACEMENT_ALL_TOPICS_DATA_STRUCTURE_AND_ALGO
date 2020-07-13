typedef pair<int,int> p;

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
   // int v=g.size();
  vector<int>dist(V,INT_MAX);
  
  priority_queue<p,vector<p>,greater<p>>pq; // dist and src
  dist[src]=0;
  pq.push({dist[src],src});

  while(!pq.empty())
  {
      int dis=pq.top().first;
      int s=pq.top().second;
      
      pq.pop();
      for(int i=0;i<V;i++)
      {
          
          if(g[s][i]&&dis+g[s][i]<dist[i])
          {
              dist[i]=dis+g[s][i];
              pq.push({dist[i],i});
          }
      }
  }
  return dist;
  
}
