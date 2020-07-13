#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int ar[],int n,int sum)
{
    int mn=n;
    for(int i=0;i<n;i++)
      {
          
          if(ar[i]>sum)
             return 1;
        int cur=0;
        for(int j=i;j<n;j++)
          {
              cur += ar[j];
               if(cur>sum)
               {
                   mn = min(mn,j-i+1);
               }
          }
      }
      return mn;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum;
	    cin>>n>>sum;
	    int ar[n];
	    for(int i=0;i<n;i++)
	      cin>>ar[i];
	     cout<<solve(ar,n,sum)<<endl;
	}
	return 0;
}
