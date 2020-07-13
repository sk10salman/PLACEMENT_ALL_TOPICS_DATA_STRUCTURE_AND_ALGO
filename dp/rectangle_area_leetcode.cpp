class Solution {
public:
    #define ll long long
vector<ll> leftt(vector<int> arr,int n)
{
      stack<pair<ll,ll>>s;
      vector<ll>v;
      for(ll i=0;i<n;i++)
        {
            if(s.size()==0)
               v.push_back(-1);
            else if(arr[i]>s.top().first)
               v.push_back(s.top().second);
            else
             {
                 while(s.size()>0 && arr[i]<=s.top().first)
                    {
                        s.pop();
                    }
                    if(s.size()==0)
                       v.push_back(-1);
                    else 
                       v.push_back(s.top().second);


             }
             s.push({arr[i],i});
        }
        return v;
}
vector<ll> rightt(vector<int> arr,int n)
{
      stack<pair<ll,ll>>s;
      vector<ll>v;
      for(ll i=n-1;i>=0;i--)
        {
            if(s.size()==0)
               v.push_back(n);
            else if(arr[i]>s.top().first)
               v.push_back(s.top().second);
            else
             {
                 while(s.size()>0 && arr[i]<=s.top().first)
                    {
                        s.pop();
                    }
                    if(s.size()==0)
                       v.push_back(n);
                    else 
                       v.push_back(s.top().second);


             }
             s.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
}

int hist(vector<int> arr,int n)
{
    vector <ll> v = leftt(arr,n);
   vector <ll> v1 = rightt(arr,n);
   ll mx = INT_MIN;
    for(ll i=0;i<n;i++)
      {
           ll x = (v1[i]-v[i]-1)*arr[i];
           mx = max(mx,x);
      }
     return mx;
}
    
    int maximalRectangle(vector<vector<char>>& M) {
        if(M.size()==0)
            return 0;
        
        int n=M.size(),m=M[0].size();
        
        if(n==0||m==0)
      return 0;
    int mx=0;
   vector<vector<int>>v(n+1,vector<int>(m+1,0));
    for(int i=0;i<m;i++)
       {
            if(M[0][i]=='0')
               v[0][i]=0;
              else
                v[0][i]=1;
       }
      mx = hist(v[0],m);
      for(int i=1;i<n;i++)
       {  for(int j=0;j<m;j++)
         {
             if(M[i][j]=='0')
               v[i][j]=0;
              else
                v[i][j]=v[i-1][j]+1;
         }
         
       }
       for(int i=1;i<v.size();i++)
         mx= max(mx,hist(v[i],m));
       return mx;
        
    }
};


/*

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6

*/
