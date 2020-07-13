class Solution {
public:
    vector<vector<int>> generate(int numRows) {
 vector<vector<int>>dp1;
        if(numRows==0)
            return dp1;
        vector<vector<int>>dp(numRows);
        dp[0].push_back(1);
        for(int i=1;i<numRows;i++)
           for(int k=0;k<=i;k++)
           {
               int x=0,y=0;
               if(k-1>=0)
                x +=dp[i-1][k-1];
               if(k<=dp[i-1].size()-1)
                   y += dp[i-1][k];
               dp[i].push_back(x+y);
           }
               return dp;
    }
};

/*
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
