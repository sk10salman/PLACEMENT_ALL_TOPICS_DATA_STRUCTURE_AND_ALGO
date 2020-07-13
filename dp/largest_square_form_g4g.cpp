#include <iostream>
using namespace std;
#define mx 50
int square(int Mat[mx][mx],int n,int m)
{
    if(n==0)
       return 0;
     int x=0;
     int dp[n][m]={0};
     for(int i=0;i<m;i++)
        {
            dp[0][i]=Mat[0][i];
            x = max(x,dp[0][i]);
        }
        for(int i=0;i<n;i++)
        {
            dp[i][0]=Mat[i][0];
            x = max(x,dp[i][0]);
        }
        for(int i=1;i<n;i++)
           for(int j=1;j<m;j++)
            if(Mat[i][j]==1)
               {
                   dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                   x = max(x,dp[i][j]);
               }
    return x;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    int arr[mx][mx];
	    for(int i=0;i<n;i++)
	       for(int j=0;j<m;j++)
	         cin>>arr[i][j];
	   cout<<square(arr,n,m)<<endl;
	}
	return 0;
}
