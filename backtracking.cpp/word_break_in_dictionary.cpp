/*
Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
set<string>s;
bool accept;
void go(string str,int len,string res)
{
    for(int i=1;i<=len;i++)
     {
         string pre = str.substr(0,i);
         if(s.find(pre)!=s.end())
           {
               if(i==len)
                {  res += pre;
                 // cout<<res<<" ";
                     accept= true;
                    return;
                    }
                    go(str.substr(i,len-i),len-i,res + pre+" ");
           }
        //  else if(if(s.find(pre)!=s.end()))
            //  return false;
          
     }
   // return false;
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
	    
	    int n;
	    cin>>n;
	    s.clear();
	    accept=false;
	    for(int i=0;i<n;i++)
	    {
	        string st;
	        cin>>st;
	        s.insert(st);
	    }
	    string str;
	    cin>>str;
	    go(str,str.length(),"");
	   cout<<accept<<endl;
	}
	return 0;
}
