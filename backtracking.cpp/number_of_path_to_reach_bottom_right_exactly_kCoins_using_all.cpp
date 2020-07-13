#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ar[200][200];
int solve(int ar[200][200],int i,int j,int sum)
{
    if(i<0||j<0||sum<0)
      return 0;
      
     if(i==0&&j==0)
     {
         if(sum==ar[i][j])
           return 1;
          return 0;
     }
      return solve(ar,i-1,j,sum-ar[i][j])+solve(ar,i,j-1,sum-ar[i][j]);
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int x;
	    cin>>x;
	    int n;
	     cin>>n;
	     memset(ar,0,sizeof(ar));
	    for(int i=0;i<n;i++)
	      for(int j=0;j<n;j++)
	        cin>>ar[i][j];
	    cout<<solve(ar,n-1,n-1,x)<<endl;
	}
	return 0;
}
