class Solution {
public:
    bool dfs(vector<vector<int>>& graph,bool color[],bool visit[],int u,int c)
    {
        visit[u]=1;
        color[u]=c;
        
        for(auto i:graph[u])
        {
            if(!visit[i])
            {
                if(dfs(graph,color,visit,i,c^1)==false)
                    return false;
            }
            else if(color[i]==color[u])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int V=graph.size();
        bool color[V];
        bool visit[V];
        memset(color,false,sizeof(color));
        memset(visit,false,sizeof(visit));
        
        for(int i=0;i<V;i++)
        {
            if(visit[i]==false)
            {
                if(dfs(graph,color,visit,i,1)==false)
                    return false;
            }
        }
        return true;
    }
};

/*
Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.


G4G


/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
   bool dfs(vector<vector<int>>& graph,bool color[],bool visit[],int u,int c)
    {
        visit[u]=1;
        color[u]=c;
        
        for(auto i:graph[u])
        {
            if(!visit[i])
            {
                if(dfs(graph,color,visit,i,c^1)==false)
                    return false;
            }
            else if(color[i]==color[u])
                return false;
        }
        return true;
    }
bool isBipartite(int g[][MAX],int V)
{
     //Your code here
     vector<vector<int>>graph(V);
      for(int i=0;i<V;i++)
         for(int j=0;j<V;j++)
           {
               if(g[i][j]==1)
                 graph[i].push_back(j);
           }
         bool color[V];
        bool visit[V];
        memset(color,false,sizeof(color));
        memset(visit,false,sizeof(visit));
        
        for(int i=0;i<V;i++)
        {
            if(visit[i]==false)
            {
                if(dfs(graph,color,visit,i,1)==false)
                    return false;
            }
        }
        return true;
}
