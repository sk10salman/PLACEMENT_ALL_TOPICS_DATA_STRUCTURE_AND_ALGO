class Solution {
public:
    vector<int>v;
    void print(vector<vector<int>>& mat,int row,int col,int m,int n)
    {
        if(row>=m||col>=n)
            return;
        for(int p=col;p<n;p++)   // insert first row
            v.push_back(mat[row][p]);
        for(int p=row+1;p<m;p++)       // insert last col
            v.push_back(mat[p][n-1]);
        if(m-1!=row)
        for(int p=n-2;p>=col;p--)    // last row ??not include already visited
            v.push_back(mat[m-1][p]);
       if((n-1)!=col)
           for(int p=m-2;p>row;p--)   // first row not include visied element reverse
              v.push_back(mat[p][col]);
               
         print(mat,row+1,col+1,m-1,n-1);
    }
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        if(mat.size()==0)
            return v;
        int m=mat.size(),n=mat[0].size();
        print(mat,0,0,m,n);
        return v;
    }
};

/*
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
