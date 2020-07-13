#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    long long count=1;
	    map<int,int>m;
	    int n;
	    cin>>n;
	    int ar[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>ar[i];
	        
	        for(int k=2;k*k<=ar[i];k++)
	          {
	              while(ar[i]%k==0)
	                m[k]++,ar[i] /=k;
	          }
	          if(ar[i]>1)
	            m[ar[i]]++;
	    }
	    for(auto x:m)
	       count *= (x.second+1);
	   cout<<count<<endl;
	}
	return 0;
}

///  using prime factorization

