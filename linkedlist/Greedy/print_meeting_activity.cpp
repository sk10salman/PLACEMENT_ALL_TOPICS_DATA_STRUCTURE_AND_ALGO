#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool cmp1(const vector<int>&a,const vector<int>&b)
{
    if(a[1]==b[1])
    {
        return a[0]>b[0];
    }
    return a[1]<b[1];
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
	    vector<vector<int>>v(n,vector<int>(3,0));
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        v[i][0]=x;
	        
	    }
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        v[i][1]=x;
	        v[i][2]=i+1;
	    }
	    sort(v.begin(),v.end(),cmp1);
	    
	    int s=v[0][1];
	    cout<<v[0][2]<<" ";
	    for(int i=0;i<v.size();i++)
	    {
	        if(s<=v[i][0])
	        {
	            
	           cout<<v[i][2]<<" ";
	           s=v[i][1];
	        }
	    }
	    cout<<endl;
	}
	return 0;
}



/*

2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  

Output:
1 2 4 5
6 7 1

Explanation:
Testcase 1: Four meetings can held with given start and end timings.
*/
