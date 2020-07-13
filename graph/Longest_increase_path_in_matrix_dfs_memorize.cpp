class Solution {
public:
    vector<vector<int>> grey;
vector<vector<int>> memo;
int dfs(int i,int j,vector<vector<int>>& m)
{
    if(memo[i][j]!=-1)
    	return memo[i][j];
    grey[i][j]=1;
    int q=INT_MIN;
    if(i+1<m.size()&&!grey[i+1][j]&&m[i][j]<m[i+1][j])
    	q=max(q,1+dfs(i+1,j,m));
    if(j+1<m[0].size()&&!grey[i][j+1]&&m[i][j]<m[i][j+1])
    	q=max(q,1+dfs(i,j+1,m));
    if(i>0&&!grey[i-1][j]&&m[i][j]<m[i-1][j])
    	q=max(q,1+dfs(i-1,j,m));
    if(j>0&&!grey[i][j-1]&&m[i][j]<m[i][j-1])
    	q=max(q,1+dfs(i,j-1,m));
    if(q==INT_MIN)
    	q=1;
    grey[i][j]=0;
    return memo[i][j]=q;
}
int longestIncreasingPath(vector<vector<int>>& arr) 
{
    int n=arr.size();
    if(!n)
        return 0;
    int m=arr[0].size();
    if(!m)
        return 0;
    int ret=0;
	grey.resize(n,vector<int>(m,0)); 
	memo.resize(n,vector<int>(m,-1));  
	for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            ret=max(ret,dfs(i,j,arr));
    return ret;
}
};
/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

