#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int ar[n];
	    for(int i=0;i<n;i++)
	      cin>>ar[i];
	     sort(ar,ar+n);
	     map<vector<int>,int>m;
	     for(int i=0;i<=n-4;i++)
	       for(int j=i+1;j<=n-3;j++)
	         {
	             int l=j+1,x=n-1;
	             while(l<x)
	             {
	                 int s=ar[i]+ar[j]+ar[l]+ar[x];
	                 if(k==s)
	                 {
	                     vector<int>v{ar[i],ar[j],ar[l],ar[x]};
	                     m[v]++;
	                     x--;
	                 }
	                 else if(k>s)
	                    l++;
	                   else if(s>k)
	                     x--;
	                      
	             }
	         }
	         if(m.size()==0)
	            cout<<"-1"<<endl;
	         else
	         {
	             for(auto it=m.begin();it!=m.end();it++)
	              {
	                  vector<int>v=it->first;
	                  for(int i=0;i<v.size();i++)
	                     cout<<v[i]<<" ";
	                    cout<<"$";
	              }
	              cout<<endl;
	         }
	}
	return 0;
}
