#include<iostream>
using namespace std;
#include<bits/stdc++.h>
string solve( vector<string>&v, vector<bool>&vis,char c,int index)
{
    string k="";
    for(int l=0;l<v.size();l++)
     {
         if(vis[l]==false&& v[l][index]==c)
         {
             k+= v[l];
             k +=" ";
         }
         else
         {
             vis[l]=true;
         }
     }
     if(k.length()==0)
       k ="0";
     return k;
}
int main()
 {
     int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       set<string>s;
       vector<string>v;
       vector<bool>vis(n,false);
       for(int i=0;i<n;i++)
        {
            string val;
            cin>>val;
            s.insert(val);
        }
   for(auto i=s.begin();i!=s.end();i++)
     {
         v.push_back(*i);
     }
       string str;
       cin>>str;
       for(int i=0;i<str.length();i++)
       {
           string s1=solve(v,vis,str[i],i);
           cout<<s1<<endl;
       }
       
    }
    return 0;
}



/*
1
3
geeikistest geeksforgeeks geeksfortest
geeips

Output:

geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
Explanation:

By running the query on contact list, we get, 
Suggestions based on "g" are: 
geeikistest geeksforgeeks geeksfortest 
Suggestions based on "ge" are:
geeikistest geeksforgeeks geeksfortest
Suggestions based on "gee" are:
geeikistest geeksforgeeks geeksfortest
Suggestions based on "geei" are:
geeikistest
No Results Found for "geeip", So print "0".
No Results Found for "geeips", So print "0".
