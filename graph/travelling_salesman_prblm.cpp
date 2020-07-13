#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int TSP(vector<vector<int>>v,int s)
{
    vector<int>vertex;
    for(int i=0;i<v.size();i++)
     {
         if(i!=s)
           vertex.push_back(i);
     }
     int ans=INT_MAX;
     do
     {
         int k=s;
         int temp=0;
         for(int i=0;i<vertex.size();i++)
         {
             temp += v[k][vertex[i]];
             k=vertex[i];
         }
         temp += v[k][s];
         ans=min(ans,temp);
     }while(next_permutation(vertex.begin(),vertex.end()));
     return ans;
}
int main() {
	//code
		int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<vector<int>>v(n);
	    for(int i=0;i<n;i++)
	    {
	      
	        for(int j=0;j<n;j++)
	           {
	               int a;
	               cin>>a;
	               v[i].push_back(a);
	           }
	           
	    }
	   cout<<TSP(v,0)<<endl;
	}
	return 0;
}
