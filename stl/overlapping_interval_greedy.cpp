//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> , int );

// User code will be pasted here

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int> > arr,res;
        int n,x,y;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            arr.push_back(make_pair(x,y));
        }
        
        res = overlappedInterval(arr,n);
        
        
        for(int i=0;i<res.size();i++)
            cout << res[i].first << " " << res[i].second << " " ;
            
        cout<<endl;
    }
}
// } Driver Code Ends


//User function template for C++
bool cmd(pair<int,int>&a,pair<int,int>&b)
{
    return a.first<b.first;
}

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n) {
    //code here
    sort(vec.begin(),vec.end());
    vector<pair<int,int>>v;
    
    v.push_back({vec[0].first,vec[0].second});
    for(int i=1;i<vec.size();i++)
     {
          int x=v.back().first;
         if(vec[i].first<=v.back().second)
          {
             if(vec[i].second>v.back().second)
            {v.pop_back();
             v.push_back({x,vec[i].second});}
          }
          else if(vec[i].first>v.back().second)
          {
              v.push_back({vec[i].first,vec[i].second});
          }
     }
     return v;
    
}
