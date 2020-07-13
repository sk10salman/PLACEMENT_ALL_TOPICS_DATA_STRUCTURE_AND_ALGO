#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dx[]={2,2,-2,-2,1,-1,1,-1};
int dy[]={1,-1,1,-1,2,2,-2,-2};
int dis[30][30];
bool vis[30][30];
int arr[30][30];
int N,M;
bool isvalid(int x,int y)
{
    if(x<=0||x>N||y<=0||y>M||vis[x][y]==1)
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
                dis[newX][newY]=dis[x][y]+1;
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
	   
	    cin>>N>>M;
	    memset(vis,0,sizeof(vis));
	    memset(dis,-1,sizeof(dis));
	   // memset(arr,0,sizeof(arr));
	    int srcx,srcy,endx,endy;
	    cin>>srcx>>srcy>>endx>>endy;
	    bfs(srcx,srcy);
	    
	    cout<<dis[endx][endy]<<endl;
	}
	return 0;
}

/*
Given a chess board of order N x M and source points (s1, s2) and destination points (d1, d2). The task to find minimum number of moves required by the Knight to go to the destination cell.
Input:
2
4 7
2 6 2 4
7 13
2 8 3 4

Output:
2
3

Explanation:
Testcase 1: One possible move for Knight is from 2, 6 to 4, 5 and then to 2, 4 which is our destination.]
