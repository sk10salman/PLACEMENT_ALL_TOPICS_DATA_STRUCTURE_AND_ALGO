#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int adj[101][101];
int N,M,fresh_orange;

queue<pair<int,int>>q;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


bool isvalid(int x,int y)
{
    if(x<0||x>=N||y<0||y>=M)
      return false;
      return true;
}

int bfs()
{
    int count=0;
    while(!q.empty())
    {
        int size=q.size();
         bool flag=false;
         for(int k=0;k<size;k++)
         {
        int x=q.front().first;
        int y=q.front().second;
        
        q.pop();
        
       
        for(int i=0;i<4;i++)
        {
            int newX=x+dx[i];
            int newY=y+dy[i];
            if(isvalid(newX,newY)&&adj[newX][newY]==1)
            {
               
                adj[newX][newY]=2;
                fresh_orange--;
                if(flag==false)
                {
                    count++;
                    flag=true;
                }
                q.push({newX,newY});
            }
        }
         }
    }
    if(fresh_orange==0)
      return count;
     return -1;
}

int main()
 {
	//code
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    memset(adj,0,sizeof(adj));
	   
	     queue<pair<int,int>>p;
	     q=p;
	     fresh_orange=0;
	     cin>>N>>M;
	     for(int i=0;i<N;i++)
	     for(int j=0;j<M;j++)
	     {
	         cin>>adj[i][j];
	         if(adj[i][j]==1)
	           fresh_orange++;
	           else if(adj[i][j]==2)
	           {
	               q.push({i,j});
	           }
	     }
	     cout<<bfs()<<endl;
	}
	return 0;
}

/*
Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.




2
3 5
2 1 0 2 1 1 0 1 2 1 1 0 0 2 1
3 5
2 1 0 2 1 0 0 1 2 1 1 0 0 2 1

Output:
2
-1

Explanation:
Testcase 1:
2 | 1 | 0 | 2 | 1
1 | 0 | 1 | 2 | 1
1 | 0 | 0 | 2 | 1

Oranges at positions {0,0}, {0, 3}, {1, 3} and {2, 3} will rot oranges at {0, 1}, {1, 0}, {0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st unit time. And, during 2nd unit time, orange at {1, 0} got rotten and will rot orange at {2, 0}. Hence, total 2 unit of time is required to rot all oranges.
