#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll prime[100001];
void sieve()
{
    memset(prime,0,sizeof(prime));
    prime[0]=prime[1]=1;
    for(int i=2;i*i<=100000;i++)
    {
        if(!prime[i])
        {
            for(int j=i*i;j<=100000;j += i)
              prime[j]=1;
        }
    }
}
int main()
 {
	//code
	int t;
	cin>>t;
	sieve();
	while(t--)
	{
	    int l,r;
	    cin>>l>>r;
	    for(int i=l;i<=r;i++)
	    {
	        if(!prime[i])
	           cout<<i<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
