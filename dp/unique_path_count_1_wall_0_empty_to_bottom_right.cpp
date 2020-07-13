class Solution {
public:
    int count;
    int solve(vector<vector<int>>& grid,int i,int j,int n,int m, vector<vector<int>>&dp)
    {
        if(i>=n||j>=m||grid[i][j]==1)
            return 0;
        if(i==n-1&&j==m-1)
        {
         
            return 1;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
         return dp[i][j]=solve(grid,i+1,j,n,m,dp)+solve(grid,i,j+1,n,m,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        if(grid[0].size()==0)
            return 0;
         count=0;
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return solve(grid,0,0,grid.size(),grid[0].size(),dp);
      
    }
};
/*
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
