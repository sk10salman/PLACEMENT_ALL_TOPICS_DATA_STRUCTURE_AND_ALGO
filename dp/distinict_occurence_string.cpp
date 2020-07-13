
/*You are required to complete this method*/


int subsequenceCount(string S, string T)
{
  //Your code here
    int n=T.length();
    int m=S.length();
    if(n>m)
      return 0;
    int dp[m+1][n+1];
    for(int i=0;i<=n;i++)
      {
          dp[0][i]=0;
      }
    for(int i=0;i<=m;i++)
      {
          dp[i][0]=1;
      }
       
    for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++)
      {
          if(S[i-1]==T[j-1])
           {  dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]);
               dp[i][j] %=1000000007;
           }
           
          else
            dp[i][j]=dp[i-1][j];
      }
     return dp[m][n];
}
 
/*

2
banana ban
geeksforgeeks ge
Output
3
6
Explanation:
(i) For first test case  S = banana, T = ban there are 3 sub-sequences which are [ban], [ba n], [b an].
(ii) For second test case S = geeksforgeeks, T=ge there are 6 sub-sequences which are  [ge], [ ge], [g e], [g e] [g e] and [ g e].
