class Solution {
public:
    int mx=INT_MIN;
    void backtrack(vector<vector<int>> &grid,int ans,int x,int y)
    {
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]==0)
            return ;
        ans += grid[x][y];
        if(ans>mx)
            mx=ans;
        int temp=grid[x][y];
        grid[x][y]=0;
        backtrack(grid,ans,x+1,y);
        backtrack(grid,ans,x-1,y);
        backtrack(grid,ans,x,y+1);
        backtrack(grid,ans,x,y-1);
        grid[x][y]=temp;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        if(grid.size()==0)
             return 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    backtrack(grid,0,i,j);
                }
            }
        return mx;
    }
};

/*
n a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
