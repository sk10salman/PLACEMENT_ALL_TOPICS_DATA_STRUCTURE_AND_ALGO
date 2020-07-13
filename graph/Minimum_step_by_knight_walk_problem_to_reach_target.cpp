#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dx[]={2,2,-2,-2,1,-1,1,-1};
int dy[]={1,-1,1,-1,2,2,-2,-2};
int dis[21][21];
bool vis[21][21];
int arr[21][21];
int N;
bool isvalid(int x,int y)
{
    if(x<0||x>N||y<0||y>N||vis[x][y]==1)
       return false;
      return true;
}
void bfs(int srcx,int srcy)
{
    queue<pair<int,int>>q;
    q.push({srcx,srcy});
    dis[srcx][srcy]=0;
    vis[srcx][srcy]=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        int d=dis[x][y];
        q.pop();
        for(int i=0;i<8;i++)
        {
            int newX=x+dx[i];
            int newY=y+dy[i];
            if(isvalid(newX,newY))
            {
                dis[newX][newY]=d+1;
                vis[newX][newY]=1;
                q.push({newX,newY});
            }
        }
    }
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   
	    cin>>N;
	    memset(vis,0,sizeof(vis));
	    memset(dis,0,sizeof(dis));
	    memset(arr,0,sizeof(arr));
	    int srcx,srcy,endx,endy;
	    cin>>srcx>>srcy;
	    cin>>endx>>endy;
	    bfs(srcx,srcy);
	    cout<<dis[endx][endy]<<endl;
	}
	return 0;
}
/*
Given a square chessboard of N x N size, the position of Knight and position of a target is given. We need to find out minimum steps a Knight will take to reach the target position.

2
6
4 5
1 1
20
5 7
15 20

Output:
3
9

Explanation:
Testcase 1:
The most optimal path is: (4,5) -> (2,4) -> (3,2) -> (1,1). 
Hence, we can reach the destination in 3 steps.
