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
	    int n,x,k;
	    cin>>n>>x>>k;
	    vector<int>v(n);
	    for(int i=0;i<n;i++)
	      cin>>v[i];
	    for(int i=0;i<k;i++)
	    {
	        int l,r;
	        cin>>l>>r;
	        l %=n,r%=n;
	       int x=v[r];
	       v.erase(v.begin()+r);
	       v.insert(v.begin()+l,x);
	    }
	    cout<<v[x]<<endl;
	}
	return 0;
}
/*
2
5 1 2
1 2 3 4 5
0 2 0 3
3 2 1
1 2 3
0 1

Output:
3
3

Explanation:
Testcase 1: Rotating the elements in range 0-2 and 0-3, we have array as 4 3 1 2 5. Element at first position is 3.


