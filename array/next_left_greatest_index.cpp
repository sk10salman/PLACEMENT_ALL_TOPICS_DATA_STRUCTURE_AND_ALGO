#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the size of array:  ";
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    vector<int>v;
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
          v.push_back(-1);
        else if(s.size()>0 && s.top().first>ar[i])
          v.push_back(s.top().second);
        else
           {
               while(s.size()>0&&s.top().first<ar[i])
                  s.pop();
                if(s.size()==0)
                   v.push_back(-1);
                else
                  v.push_back(s.top().second);
           }
           s.push({ar[i],i});
    }
    cout<<endl;
    for(int i=0;i<v.size();i++)
       {
           cout<<v[i]<<" ";
       }
}