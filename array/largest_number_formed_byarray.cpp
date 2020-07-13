#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool fun(int num1,int num2)
{
    if(num1==num2)
     {
         return num1<num2;
     }
     string s1=to_string(num1);
     string s2=to_string(num2);
     if(s1+s2>s2+s1)
        return true;
    return false;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int ar[n],arr[n];
	    for(int i=0;i<n;i++)
	       {cin>>ar[i];arr[i]=ar[i];}
	       sort(ar,ar+n,fun);
	   string s1="";
	   for(int i=0;i<n;i++)
	      s1.append(to_string(ar[i]));
	   cout<<s1<<endl;
	}
	return 0;
}


/*
2
5
3 30 34 5 9
4
54 546 548 60

Output:
9534330
6054854654


*/
