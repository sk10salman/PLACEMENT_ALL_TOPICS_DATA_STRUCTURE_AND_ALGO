#include<bits/stdc++.h>
using namespace std;

bool safe(vector<vector<int>>&mat,int i,int j)
{
    int n=mat.size();
    if(i<0 || j<0 || i>=n || j>=n)
        return false;
    return true;
}
int solve(vector<vector<int>>ar,int n)
{
    int dx[]={-1,0,1,0};
    int dy[]={0,-1,0,1};
  
    vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push(make_pair(ar[0][0],make_pair(0,0)));
       dis[0][0]=ar[0][0];
    while(!pq.empty())
    {
        int w=pq.top().first;
        int u=pq.top().second.first;
        int v=pq.top().second.second;
        pq.pop();
        for(int i=0;i<4;i++)
        {
            int x=u+dx[i];
            int y=v+dy[i];
            if(safe(dis,x,y) && dis[x][y]>w+ar[x][y])
            {
                dis[x][y]=w+ar[x][y];
                pq.push(make_pair(dis[x][y],make_pair(x,y)));
            }
        }
    }
    return dis[n-1][n-1];
}
int main()
{
    int t;
cin>>t;

while(t--)
{
    int n;
     cin>>n;
     
     vector<vector<int>>ar(n,vector<int>(n));
     for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        {int x;
            cin>>ar[i][j];
            
        }
     cout<<solve(ar,n)<<endl;

}


}
