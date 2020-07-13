#include<bits/stdc++.h>
using namespace std;
struct Graph
{
    int v;
    int e;
    int **adj;
};
struct  Graph *Adjii()
{
    /* data */
    int v,e;
    struct Graph *g=(struct Graph *)malloc(sizeof(struct Graph));
    cout<<"enter the nodes and edges : ";
    cin>>g->v>>g->e;
   
    g->adj = (int *)malloc(sizeof(int)*(g->v*g->v));
    for(int i=0;i<g->v;i++)
      for(int j=0;j<g->v;j++)
         g->adj[i][j]=0;

for(int i=0;i<g->v;i++)
      for(int j=0;j<g->v;j++)
         cout<<g->adj[i][j];
        return g;
}
int main()
{
   Graph *g = Adjii();
  /* for(int i=0;i<g->v;i++)
      for(int j=0;j<g->v;j++)
         cout<<g->adj[i][j]<<" ";
 cout<<g->v<<g->e<<endl;*/
 
         return 0;
}
