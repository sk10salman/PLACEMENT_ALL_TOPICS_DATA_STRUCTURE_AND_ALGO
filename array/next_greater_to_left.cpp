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
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
          v.push_back(-1);
        else if(s.size()>0 && s.top()>ar[i])
          v.push_back(s.top());
        else
           {
               while(s.size()>0&&s.top()<ar[i])
                  s.pop();
                if(s.size()==0)
                   v.push_back(-1);
                else
                  v.push_back(s.top());
           }
           s.push(ar[i]);
    }
    cout<<endl;
    for(int i=0;i<v.size();i++)
       {
           cout<<v[i]<<" ";
       }
}