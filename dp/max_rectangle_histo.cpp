#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends
/*You are required to complete this method*/
#include<bits/stdc++.h>
#define ll long long
vector<ll> leftt(int arr[],int n)
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
vector<ll> rightt(int arr[],int n)
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

int hist(int arr[],int n)
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
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    if(n==0||m==0)
      return 0;
    int mx=0;
    int v[m+1]={0};
    for(int i=0;i<m;i++)
       {
           v[i]=(M[0][i]);
       }
       mx = hist(v,m);
      for(int i=1;i<n;i++)
       {  for(int j=0;j<m;j++)
         {
             if(M[i][j]==0)
               v[j]=0;
              else
                v[j]+=1;
         }
         mx = max(mx,hist(v,m));
       } 
       return mx;
}

