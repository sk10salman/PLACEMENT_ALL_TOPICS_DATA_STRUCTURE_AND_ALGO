#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void backtrack( set<vector<int>>&result,vector<int>v,int index,vector<int>&row,int sum)
{
    if(sum<0)
      return;
     if(sum==0)
      {
          result.insert(row);
          return;
      }
      if(index>=v.size())
        return;
     row.push_back(v[index]);
      backtrack(result,v,index+1,row,sum-v[index]);
     row.pop_back();
    
       backtrack(result,v,index+1,row,sum);
     
}
int main()
 {
	//code
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n;
	    vector<int>v;

	    for(int i=0;i<n;i++)
	      {cin>>x;
	       
	            v.push_back(x);
	      }
	     sort(v.begin(),v.end());
	     int B;
	     cin>>B;
	     set<vector<int>>result;
	     vector<int>row;
	     backtrack(result,v,0,row,B);
	     if(result.empty())
	      cout<<"Empty";
	    for(auto j=result.begin();j!=result.end();j++)
	    {
	        vector<int>temp=*j;
	        cout<<"(";
        int i;
        for(i=0;i<temp.size()-1;i++){
            cout<<temp[i]<<" ";
        }
        cout<<temp[i]<<")";
	    }
	    cout<<"\n";
	}
	return 0;
}

/*
One line per test case, every subset enclosed in () and in every set intergers should be space seperated.(See example)

Example:
Input:
2
7
10 1 2 7 6 1 5
8
5
8 1 8 6 8
12

Output:
(1 1 6)(1 2 5)(1 7)(2 6)
Empty


