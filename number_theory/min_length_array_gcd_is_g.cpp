#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n;
int g;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>g;
	    cin>>n;
	    int ar[n];
	    for(int i=0;i<n;i++)
	       cin>>ar[i];
	   int ans=INT_MAX;
	   for(int i=0;i<n-1;i++)
	    {   int gc=ar[i];
	        for(int j=i+1;j<n;j++)
	        {
	            gc=__gcd(gc,ar[j]);
	            if(gc==g)
	            ans=min(j-i+1,ans);
	        }
	   }
	   if(ans==INT_MAX)
	     ans=-1;
	   cout<<ans<<endl;
	   
	}
	return 0;
}
