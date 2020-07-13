#include<bits/stdc++.h>
using namespace std;
void knap(int ar[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
       dp[i][0]=1;
       for(int i=1;i<=sum;i++)
       dp[0][i]=0;
       for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=sum;j++)
               {
                   if(ar[i-1]<=j)
                      dp[i][j]= (dp[i-1][j-ar[i-1]]+dp[i-1][j]);
                    else
                       dp[i][j]=dp[i-1][j];
               }
         }
    for(int i=0;i<=n;i++)
     {    cout<<endl;
          { for(int j=0;j<=sum;j++)
         cout<<dp[i][j]<<" ";
         }}
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
       cin>>ar[i];
       int sum;
       cin>>sum;
       knap(ar,n,sum);
       return 0;
}