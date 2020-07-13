#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	  
	    string s;
	    cin>>s;
	    int n=s.length();
	    map<string,int>m;
	    int dp[n][n];
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<n;i++)
	    dp[i][i]=1;
	    for(int i=0;i<n-1;i++)
	     if(s[i]==s[i+1])
	       dp[i][i+1]=1;
	    for(int k=3;k<=n;k++)
	    {
	        for(int i=0;i<n-k+1;i++)
	        {
	            int j=i+k-1;
	            if(dp[i+1][j-1]==1&&s[i]==s[j])
	            {
	                dp[i][j]=1;
	            }
	        }
	    }
	    int count=0;
	    for(int i=0;i<n;i++)
	      for(int j=0;j<n;j++)
	      {
	          if(dp[i][j]==1)
	            m[s.substr(i,j-i+1)];
	      }
	      cout<<m.size()<<endl;
	}
	return 0;
}
