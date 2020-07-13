class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       if(matrix.size()==0)
           return;
        int n=matrix.size(),m=matrix[0].size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                    v.push_back({i,j});
            }
        for(int i=0;i<v.size();i++)
        {
            for(int k=0;k<n;k++)
                matrix[k][v[i].second]=0;
            for(int k=0;k<m;k++)
                matrix[v[i].first][k]=0;
        }
        
    }
};
/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
