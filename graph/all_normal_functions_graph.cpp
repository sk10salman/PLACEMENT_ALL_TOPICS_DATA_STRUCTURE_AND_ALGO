/****  DFS****************************************************************************************************/
void dfs(int s, vector<int> g[], bool vis[])
{

    // Your code here
    vis[s]=true;
    cout<<s<<" ";
    for(auto i:g[s])
    {
        if(!vis[i])
         dfs(i,g,vis);
    }
   
}
/*     *******************************  BFS    **********************************(((((((****************************************************/


void BFS(int s,vector<int> adj[],int V) 
{ 
	bool vis[V];
	memset(vis,false,sizeof(vis));
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        
        cout<<front<<" ";
        for(auto x:adj[front])
        {
            if(!vis[x])
             { q.push(x);
                vis[x]=true;
             }
        }
    }
} 

/*                 ********  *        *****************************************************************************************         */

        //DETECT CYCLE IN UNDIRECTED GRAPH   


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
    //vis[u]=false;
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

/*             ****************       *****************************************************************************************   */
             //DETECT CYCLE IN DIRECTED GRAPH



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

/*     ******************* ********************************************************************************************************  */
          //  topological SORT    
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

/*       *************************************** **************************************************************************************** */
               // BIPARITE GRAPH    is posible to divide two graph 
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

/* ***********************************************************************************************************************************/

      // Shotest_path_SOURCE_TO_DESTINATION (0,0) to(t1,t2)
set<int>s;
void mark_island(vector<vector<int>>A,int x,int y,vector<vector<int>>vis,int r,int c,int count,int t1,int t2)
{
    if(x<0||x>=r||y<0||y>=c||A[x][y]!=1||vis[x][y]==true)
      return;
      if(x==t1&& y==t2)
       s.insert(count);
     vis[x][y]=true;
     count++;
     
     mark_island(A,x+1,y,vis,r,c,count,t1,t2);

      mark_island(A,x-1,y,vis,r,c,count,t1,t2);
       mark_island(A,x,y+1,vis,r,c,count,t1,t2);
        mark_island(A,x,y-1,vis,r,c,count,t1,t2);
         
     
}
  ///// if there is no Path print -1
int findIslands(vector<int> A[], int N, int M,int x,int y) {

    // Your code here
    vector<vector<int>>mat;
    for(int i=0;i<N;i++)
      mat.push_back(A[i]);
    int no_of_island=0;
   vector<vector<int>>vis(N,vector<int>(M,false));
                 int count=0;
                 mark_island(mat,0,0,vis,N,M,count,x,y);
                
       
       int m=-1;
      if(!s.empty())
        m=*s.begin();
    s.clear();
      return m;
}

/*    *****************************************************************************  ****************************************************/

                  //word Search IN WOGGLE

// User function template for C++
void dfs(bool &accept,vector<vector<char> >& board,int x,int y,string word,int pos)
{
    if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]!=word[pos])
       return ;
     if(pos==word.length()-1)
      {
          accept=true;
          return;
      }
    char temp=board[x][y];
    board[x][y]=' ';
   
    dfs(accept,board,x+1,y,word,pos+1);
    dfs(accept,board,x-1,y,word,pos+1);
    dfs(accept,board,x,y+1,word,pos+1);
    dfs(accept,board,x,y-1,word,pos+1);
    dfs(accept,board,x+1,y+1,word,pos+1);
    dfs(accept,board,x+1,y-1,word,pos+1);
    dfs(accept,board,x-1,y+1,word,pos+1);
    dfs(accept,board,x-1,y-1,word,pos+1);
    
    board[x][y]=temp;
    
}

vector<string> boggle(vector<vector<char> >& board,
                      vector<string>& dictionary) {
    // Your code goes here
    vector<string>v;
    for(int k=0;k<dictionary.size();k++)
    {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==dictionary[k][0])
                {
                    bool accept=false;
                    dfs(accept,board,i,j,dictionary[k],0);
                  if(accept==true)
                  {
                      v.push_back(dictionary[k]);
                      i=board.size();
                      j=board[0].size();
                  }
                }
            }
        }
    }
    return v;
}

1
4
GEEKS FOR QUIZ GO
3 3
G I Z 
U E K 
Q S E
Output:
GEEKS QUIZ


/******************************************************************************************************************************************/

           //////  DIJSTRA ALGORITHM

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

/*****************************************************************************************************************************************/
