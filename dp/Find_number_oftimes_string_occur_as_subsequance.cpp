#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int go(string a,string b,string res,int a1,int b1,int n,int m,vector<vector<int>>&dp)
{
    if(res==b)
     {
         return 1;
     }
     if(a1==n)
      { return 0;}
    if(a[a1]==b[b1])
    {
        return go(a,b,res,a1+1,b1,n,m,dp)+go(a,b,res+a[a1],a1+1,b1+1,n,m,dp);
    }
    else
      {
          return go(a,b,res,a1+1,b1,n,m,dp);
      }
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	
	    int n,m;
	    cin>>n>>m;
	     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	    string a,b;
	    cin>>a>>b;
	    cout<<go(a,b,"",0,0,n,m,dp)<<endl;
	}
	return 0;
}

/*
Print the number of times S2 appears in S1, whether continuous or discontinuous. Print the answer for each test case in a new line.


Constraints:

1<= T <=100

1<= N, M <=1000


Example:

Input:

1

13 3

geeksforgeeks gks

Output: 

4
