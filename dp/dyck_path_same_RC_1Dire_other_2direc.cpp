/*
Consider a n x n grid with indexes of top left corner as (0, 0). Dyck path is a staircase walk from bottom left, i.e., (n-1, 0) to top right, i.e., (0, n-1) that lies above the diagonal cells (or cells on line from bottom left to top right).

The task is to count the number of Dyck Paths from (n-1, 0) to (0, n-1).
https://practice.geeksforgeeks.org/problems/dyck-path/0
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long solve(int n,int m)
{
   /*int dp[n][m];
   for(int i=0;i<n;i++)
     dp[i][0]=1;
     for(int i=0;i<m;i++)
     dp[0][i]=1;
   
    for(int i=1;i<n;i++)
      for(int j=1;j<m;j++)
       if(i!=j)
       dp[i][j]=dp[i-1][j]+dp[i][j-1];
       else
        dp[i][j]=dp[i-1][j];
     return dp[n-1][m-1];*/
    long long  dp[31][31];
    for(int i=0;i<31;i++)
     {  dp[i][0]=1;
        dp[0][i]=1;
     } 
     for(int i=1;i<31;i++)
        for(int j=1;j<31;j++)
          if(i!=j)
           dp[i][j]= (dp[i-1][j]+dp[i][j-1]);
          else
            dp[i][j]=dp[i-1][j];
    return dp[n][m];
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    cout<<solve(n,n)<<endl;
	}
	return 0;
}
