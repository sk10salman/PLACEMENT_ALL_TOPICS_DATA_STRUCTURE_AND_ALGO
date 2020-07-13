#include<bits/stdc++.h>
int maxPalindrome(Node *head)
{
    //Your code here
    string s="";
    Node *p=head;
    while(p)
    {
        s += p->data+'0';
        p=p->next;
    }
    int n=s.length();
    int ans=0;
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
      dp[i][i]=1,ans=1;
     for(int i=0;i<n-1;i++)
       if(s[i]==s[i+1])
         dp[i][i+1]=1,ans=2;
    for(int k=3;k<=n;k++)
       for(int i=0;i<=n-k;i++)
       {
           int j=i+k-1;
           if(dp[i+1][j-1]==1&&s[i]==s[j])
           {
               dp[i][j]=1;
               ans=max(ans,j-i+1);
           }
       }
    return ans;
}
