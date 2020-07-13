#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll N,R;
ll C=1000000007;
long long power(long long a,int b,long long c)
{
    if(b<=0)
    {
        return 1;
    }
    if(b%2==0)
    {
        return power(a*a%c,b/2,c)%c;
    }
    else
    return a*power(a,b-1,c)%c;
}
ll f[1001];
void solve()
{
    f[0]=1,f[1]=1;
    for(int i=2;i<=1000;i++)
        f[i]=(f[i-1]*i)%C;
    
}

int main()
 {
	//code
	int t;
	cin>>t;
	solve();
	while(t--)
	{
	    cin>>N>>R;
	    if(R>N)
	      cout<<"0"<<endl;
	   else {ll x=f[N];
	    x = (x*power(((f[R]*f[N-R])%C),C-2,C))%C;
	   
	    cout<<x<<endl;}
	}
	return 0;
}
