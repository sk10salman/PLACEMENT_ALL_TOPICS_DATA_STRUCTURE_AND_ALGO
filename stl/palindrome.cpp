#include<bits/stdc++.h>
using namespace std;

bool lcs(string s)

{
    
     string Y=s;
     reverse(Y.begin(),Y.end());
     return s==Y;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
    string X,Y="";
    cin>>X;
    Y+=X[0];
    set<string>s;
     int x=0;
    for(int i=0;i<X.length();i++)
     {
         string b="";
         for(int j=i;j<X.length();j++)
         {
             b+=X[j];
            s.insert(b);
         }
     }
    for(auto a:s)
       if(Y.size()<a.size()&&lcs(a))
            Y=a;
    cout<<Y<<endl;;
    }
    return 0;
}