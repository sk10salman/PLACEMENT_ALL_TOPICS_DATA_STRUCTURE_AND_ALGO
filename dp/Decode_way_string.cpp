#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int go(string s,int pos,int n)
{
    if(pos==n)
        return 1;
    if(s[pos]=='0')
     return 0;
    int res=go(s,pos+1,n);
    if(((pos+1)<n)&&(s[pos]=='1'|| (s[pos]=='2'&&s[pos+1]<='6')))
       res += go(s,pos+2,n);
     return res;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    cout<<go(s,0,n)<<endl;
	}
	return 0;
}
/*
Given encoded message "123",  it could be decoded as "ABC" (1 2 3) or "LC" (12 3) or "AW"(1 23).
