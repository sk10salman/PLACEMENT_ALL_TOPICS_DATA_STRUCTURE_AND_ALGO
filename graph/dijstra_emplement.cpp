
/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
typedef pair<int,int> p;

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
   // int v=g.size();
    bool vis[V]={false};
     priority_queue<p,vector<p>,greater<p>>pq;//distance and destination
     vector<int>dis(V,INT_MAX);
     dis[src]=0;
    
     pq.push({0,src});
     while(pq.empty()!=true)
     {
       pair<int,int> q=pq.top();
       pq.pop();
      // if(vis[q.second]==true)
        // continue;
        vis[q.second]=true;
       for(int i=0;i<V;i++)
         {
             if(vis[i]==false)
             {
                 if(g[q.second][i]&&dis[q.second]!=INT_MAX&&dis[i]>q.first+g[q.second][i])
                  { dis[i]=q.first+g[q.second][i];
                  pq.push({dis[i],i});}
             }
         }
     }
     return dis;
}

/*
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output:
0 25
7 6 0

Explanation:
Testcase 1: Shortest distance of source node 0 to 1 is 25, and shortest distance of source to source is 0.
*/
