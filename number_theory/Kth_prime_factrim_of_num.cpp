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
	    int n,k;
	    cin>>n>>k;
	     vector<int>v;
	     for(int i=2;i*i<=n;i++)
	     {
	         if(n%i==0)
	         {
	             while(n%i==0)
	             {
	                 v.push_back(i);
	                 n /= i;
	             }
	         }
	     }
	     if(n>1)
	       v.push_back(n);
	   //for(auto x:v)
	   //  cout<<x<<"  ";
	   if(v.size()<k)
	     cout<<"-1"<<endl;
	    else
	      cout<<v[k-1]<<endl;
	}
	return 0;
}
/*
2
225 2
81 5
Ouput:
3
-1

Explanation:
Test Case 1:  n=225 and k=2 , Prime factor of 225 are: 3,3,5,5 .Kth prime factor is 3
Test Case 2: n=81 and k=5 , Prime factor of 81 is 3,3,3,3 , since k is greater than all the count of prime
factor, hence we print -1
