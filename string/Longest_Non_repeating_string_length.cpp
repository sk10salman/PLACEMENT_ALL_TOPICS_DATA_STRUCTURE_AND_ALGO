#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(string s)
{
    map<char,int>m;
    for(auto x:s)
    {
        m[x]++;
        if(m[x]>=2)
          return false;
    }
    return true;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int count=0;
	    string a ="";
	    for(int i=0;i<s.length();i++)
	    {
	        a+= s[i];
	        if(check(a))
	        {
	            int size=a.length();
	            count=std::max(size,count);
	        }
	        else
	        {
	            while(a.length()>0&&!check(a))
	            a.erase(a.begin()+0);
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}

/*
2
geeksforgeeks
qwertqwer

Output:
7
5
