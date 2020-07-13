class Solution {
public:

    int countSubstrings(string s) {
       if(s.length()<=1)
           return s.length();
       
        int count=0;
        int n=s.length();
       int mat[n][n];
        memset(mat,0,sizeof(mat));
        for(int i=0;i<n;i++)
        { mat[i][i]=1;count++;}
        for(int col=1;col<n;col++)
            for(int row=0;row<col;row++)
            {
                if(row==col-1 && s[row]==s[col])
                {
                    mat[row][col]=1;
                    count++;
                }
                else if(mat[row+1][col-1]==1&&s[row]==s[col])
                {
                      mat[row][col]=1;
                    count++;
                }
                }
        
          
        return count;
    }
};

/*
Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
