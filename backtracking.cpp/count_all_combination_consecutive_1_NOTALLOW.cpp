#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int n,int i,string res,int &count)
{
    if(i==n)
    {
        count++;
        return;
    }
    if(i>n)
       return;
    if(res.length()==0||res.back()=='0')
    {
        res.push_back('0');
        solve(n,i+1,res,count);
        res.pop_back();
        res.push_back('1');
         solve(n,i+1,res,count);
    }
    else if(res.back()=='1')
    {
     res.push_back('0');
        solve(n,i+1,res,count);   
    }
    
}
int main()
 {
	//code
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    
	    int n;
	    cin>>n;
	    int count=0;
	   solve(n,0,"",count);
	   cout<<count<<"\n";
	}
	return 0;
}
