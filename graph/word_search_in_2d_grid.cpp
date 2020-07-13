class Solution {
public:
      bool dfs(vector<vector<char>>& board,int i,int j,int count,string word)
      {
          if(count==word.size())
              return true;
          if(i<0 || i>= board.size()||j<0||j>=board[0].size()||board[i][j]!=word[count])
              return false;
          char temp=board[i][j];
          board[i][j]=' ';
          count +=1;
          bool accept = dfs(board,i+1,j,count,word)||dfs(board,i-1,j,count,word)||dfs(board,i,j+1,count,word)||dfs(board,i,j-1,count,word);
          
           board[i][j]=temp;
          return accept;
          
      }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0] && dfs(board,i,j,0,word))
                     return true;
            }
        return false;
    }
    
};


/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
