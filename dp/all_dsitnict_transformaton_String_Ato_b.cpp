#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int go(string a,string b,int i,int j)
{
    if(j==b.length())
      return 1;
     if(i==a.length())
      return 0;
     if(a[i]!=b[j])
     {
         return go(a,b,i+1,j);
     }
     else
    
         return go(a,b,i+1,j+1)+go(a,b,i+1,j);
     
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string a,b;
	    cin>>a>>b;
	    if(a==b)
	    cout<<1<<endl;
	    else
	     cout<<go(a,b,0,0)<<endl;
	}
	return 0;
}



/*
Given two sequences A, B, find out number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Example :
A = "abcccdf"  B = "abccdf"

Return 3. And the formations as follows:

A1= "ab.ccdf"
A2= "abc.cdf"
A3="abcc.df"

"." is where character is removed.



/*momorize
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>m;
int go(string a,string b,int i,int j)
{
    if(j==b.length())
      return 1;
     if(i==a.length())
      return 0;
      string st=to_string(i)+"|"+to_string(j);
      if(m.count(st))
       return m[st];
     if(a[i]!=b[j])
     {
         return m[st]=go(a,b,i+1,j);
     }
     else
    
         return m[st]=go(a,b,i+1,j+1)+go(a,b,i+1,j);
     
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    m.clear();
	    string a,b;
	    cin>>a>>b;
	    if(a==b)
	    cout<<1<<endl;
	    else
	     cout<<go(a,b,0,0)<<endl;
	}
	return 0;
}
