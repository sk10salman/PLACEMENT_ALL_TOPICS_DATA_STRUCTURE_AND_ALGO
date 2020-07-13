class NumMatrix {
	vector<vector<int>> glob;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		if(matrix.size()==0 || matrix[0].size()==0) return ;
		int m=matrix.size();
		int n=matrix[0].size();
		vector<vector<int>> dp(m+1,vector<int>(n+1,0));        
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++){
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
			}
		glob=dp;

	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if(glob.size()==0 || glob[0].size()==0) return 0;
		return glob[row2+1][col2+1]-glob[row2+1][col1]-glob[row1][col2+1]+glob[row1][col1];
	}
};

/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12

