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
	    map<int,int>m1,m2;
	    int a,b;
	    cin>>a>>b;
	  
	    for(int i=2;i*i<=a;i++)
	    {
	        while(a&&a%i==0)
	          m1[i]++,a /= i;
	    }
	    if(a>1)
	      m1[a]++;
	    
	    for(int i=2;i*i<=b;i++)
	    {
	        while(b&&b%i==0)
	          m2[i]++,b /= i;
	    }
	    if(b>1)
	      m2[b]++;
	    int count=1;
	    for(auto x:m1)
	    {
	        if(m2[x.first]!=0)
	        count *= (min(x.second,m2[x.first])+1);
	    }
	    cout<<count<<endl;
	    
	}
	return 0;
}
