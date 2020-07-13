#include <iostream>
using namespace std;
char c[50][50];
void dfs( char c[50][50],int x,int y,int n,int m)
{
    if(x<0||x>=n||y<0||y>=m||c[x][y]!='X')
      return;
     c[x][y]='O';
     dfs(c,x+1,y,n,m);
     dfs(c,x-1,y,n,m);
     dfs(c,x,y+1,n,m);
     dfs(c,x,y-1,n,m);
     
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    
	    
	    for(int i=0;i<n;i++)
	      for(int j=0;j<m;j++)
	         cin>>c[i][j];
	         int count=0;
	   for(int i=0;i<n;i++)
	     for(int j=0;j<m;j++)
	     {
	         if(c[i][j]=='X')
	          {
	              count+=1;
	              dfs(c,i,j,n,m);
	          }
	     }
	      cout<<count<<endl;
	  
	}
	return 0;
}

/*
Given N * M string array of O's and X's. The task is to find the number of 'X' total shapes. 'X' shape consists of one or more adjacent X's (diagonals not included).

Input: The first line of input takes the number of test cases T. Then T test cases follow. Each of the T test cases takes 2 input lines. The first line of each test case have two integers N and M.The second line of N space separated strings follow which indicate the elements in the array.
