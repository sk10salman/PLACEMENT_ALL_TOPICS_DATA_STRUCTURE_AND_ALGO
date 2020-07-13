#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	set<int>s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	while(t--)
	{
	    vector<int>v;
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        bool accept=true;
	        int y=x;
	        while(y)
	        {
	            if(s.find(y%10)==s.end())
	             {
	                 accept=false;
	                 break;
	             }
	             y /=10;
	        }
	        if(accept && x!=0)
	         v.push_back(x);
	    }
	    sort(v.begin(),v.end());
	    if(v.size()==0)
	      cout<<"-1";
	     else
	        for(auto a:v)
	          cout<<a<<" ";
	       cout<<endl;
	}
	return 0;
}
