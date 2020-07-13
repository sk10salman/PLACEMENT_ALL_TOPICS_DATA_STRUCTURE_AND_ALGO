#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x=0;
    for(int i=0;i<31;i++)
       x = x^(1<<i);
    x +=pow(2,31); 
    cout<<x<<endl;
    return 0;
}