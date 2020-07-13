#include <bits/stdc++.h>
#define c 39
#define coin 39
using namespace std;

long long count(int a[c][c],long long dp[c][c][coin],int m,int n,int k)
{
    if(m<0 || n<0||k<0)
        return 0;
        
    if(m==0 && n==0)
    {
        if(k==a[m][n])
            return 1;
        else
            return 0;
            
    }
        
    if(dp[m][n][k]!=0)
       return dp[m][n][k];
        
    dp[m][n][k] = count(a,dp,m-1,n,k-a[m][n]) + 
                  count(a,dp,m,n-1,k-a[m][n]);
    
    return dp[m][n][k];
}

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int k,n;
	    cin>>k>>n;
	    
	    int a[c][c];
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	            cin>>a[i][j];
	      
	    long long dp[c][c][coin] = {0};  
	    cout<<count(a,dp,n-1,n-1,k)<<endl;
	    
	}
	return 0;
}


/*
2
16
3
1 2 3 4 6 5 9 8 7
12
3
1 2 3 4 6 5 3 2 1

Output:
0
2

Explanation:
Testcase 2: There are 2 possible paths with exactly K coins, which are (1 + 4 + 3 + 2 + 1) and (1 + 2 + 3 + 5 + 1).


