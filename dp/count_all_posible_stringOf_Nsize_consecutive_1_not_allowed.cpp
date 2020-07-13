#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(int n)
{
    if(n==1)
      return 2;
     if(n==2)
      return 3;
    ll dp[n+1];
    dp[1]=2;
    dp[2]=3;
    for(int i=3;i<=n;i++)
      {
          dp[i]=(dp[i-1]+dp[i-2])%1000000007;
          dp[i] %=1000000007;
      }
      return dp[n]%1000000007;
    
}
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
	    
	    int n;
	    cin>>n;
	    int count=0;
	  
	   cout<< solve(n)<<"\n";
	}
	return 0;
}
