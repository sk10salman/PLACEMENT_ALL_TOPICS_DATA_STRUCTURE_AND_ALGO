#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long power(long long a,int b,long long c)
{
    if(b==1)
    {
        return a%c;
    }
    if(b%2==0)
    {
        return power(a*a%c,b/2,c)%c;
    }
    else
    return a*power(a,b-1,c)%c;
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
	    vector<int>ar(n);
	    for(int i=0;i<n;i++)
	      cin>>ar[i];
	    long long h=1;
	    for(auto x:ar)
	    {
	        h= (h*x)%mod;
	    }
	    int f=0;
	    for(auto x:ar)
	       f=__gcd(f,x);
	   cout<<power(h,f,mod)<<endl;
	}
	return 0;
}
/*
Given two function, one is h(x) which includes the products of all the number in an array A[ ] having size N and another function f(x) which denotes the GCD of all the numbers in an array.Your task is to find the value of  h(x)f(x).
