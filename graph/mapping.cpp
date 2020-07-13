#include<bits/stdc++.h>
using namespace std;
int main()
{
     map<int,int>v;
    for(int i=0;i<10;i++)
    {
        int x;
        cin>>x;
      v[x]++;
    }
    /*for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }*/
    
    for(auto i=v.begin();i!=v.end();i++)
    {
        cout<<i->first<<" "<<i->second<<endl;
    }
    return 0;
}