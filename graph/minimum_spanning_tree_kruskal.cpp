// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX

struct edge{
    int a,b,w;          //edge of node a<--(w)-->b 
};
int par[10001];
bool cmp(edge a,edge b)
{
    return a.w<b.w;             /// sorting using weight
}

int find(int a)
{
    if(par[a]==-1)
      return a;
    return par[a]=find(par[a]);             ////  finding its same parent of this node:
    
}

void merge(int a,int b)
{
    par[a]=b;                  //// parent means its node btw a and b
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    memset(par,-1,sizeof(par));
  vector<edge>v;
   // int ed;
    for(int i=0;i<graph.size();i++)
     for(int j=0;j<graph[0].size();j++)
     {
         if(graph[i][j]!=INT_MAX)
         v.push_back({i,j,graph[i][j]});
     }
     sort(v.begin(),v.end(),cmp);
     int sum=0;
     for(int i=0;i<v.size();i++)
     {
         int a=find(v[i].a);
         int b=find(v[i].b);
         if(a!=b)
         {
             sum += v[i].w;
             merge(a,b);
         }
     }
    return sum;
}
