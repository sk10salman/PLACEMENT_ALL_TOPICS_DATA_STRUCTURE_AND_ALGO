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
    set<pair<string,int>>s;
     int x=0;
    for(int i=0;i<X.length();i++)
     {
         string b="";
         for(int j=i;j<X.length();j++)
         {
             b+=X[j];
            s.insert({b,i});
         }
     }
     int index=0;
    for(auto a:s)
       if(Y.size()<=a.first.size()&&lcs(a.first))
          {  if(Y.size()==a.first.size())
              {
                  if(index>a.second)
                   { Y=a.first;
                      index=a.second;
                   }
              }
             else
             {
                 Y=a.first;
                 index=a.second;
             }
          }
    cout<<Y<<endl;;
    }
    return 0;
}
