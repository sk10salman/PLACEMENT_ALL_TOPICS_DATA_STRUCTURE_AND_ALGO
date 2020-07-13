#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int f(int ar[],int n)
{
    if(ar[0]==0)
      return -1;
   int dp[n];
   dp[0]=0;
   for(int i=1;i<n;i++)
    dp[i]=INT_MAX;
   for(int i=0;i<n;i++)
   {
       for(int j=i+ar[i];j>i;j--)
       {
           if(j<n)
           {
               dp[j]=min(dp[j],dp[i]+1);
           }
       }
   }
   if(dp[n-1]==INT_MAX)
     return -1;
    return dp[n-1];
   
    
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int ar[n];
	    for(int i=0;i<n;i++)
	       cin>>ar[i];
	      cout<<f(ar,n)<<endl;
	}
	return 0;
}
