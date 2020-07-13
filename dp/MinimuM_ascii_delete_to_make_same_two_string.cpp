class Solution {
public:
    #define ll long long
      int dp[1002][1002];
    ll go(string s1, string s2,int n,int m,  int dp[1002][1002])
    {
        ll cost=0;
        if(dp[n][m] != (-1))
            return dp[n][m];
        if(n==0&&m==0)
        {
          
            return 0;
        }
        else if(n==0)
        {
           return dp[n][m]=go(s1,s2,n,m-1,dp)+s2[m-1];
        }
        else if(m==0)
        {
           return dp[n][m]=go(s1,s2,n-1,m,dp)+s1[n-1];
        }
        
        else if(s1[n-1]==s2[m-1])
        {
            return dp[n][m]= go(s1,s2,n-1,m-1,dp);
          
        }
        return dp[n][m]= min(go(s1,s2,n-1,m,dp)+s1[n-1],go(s1,s2,n,m-1,dp)+s2[m-1]);
    }
    int minimumDeleteSum(string s1, string s2) { 
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        
        memset(dp,-1,sizeof(dp));
        return go(s1,s2,s1.length(),s2.length(),dp);
    }
};

/*
Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
