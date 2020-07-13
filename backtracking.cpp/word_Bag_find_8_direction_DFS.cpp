void dfs(bool &accept,vector<vector<char> >& board,int x,int y,string word,int pos)
{
    if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y]!=word[pos])
       return ;
     if(pos==word.length()-1)
      {
          accept=true;
          return;
      }
    char temp=board[x][y];
    board[x][y]=' ';
   
    dfs(accept,board,x+1,y,word,pos+1);
    dfs(accept,board,x-1,y,word,pos+1);
    dfs(accept,board,x,y+1,word,pos+1);
    dfs(accept,board,x,y-1,word,pos+1);
    dfs(accept,board,x+1,y+1,word,pos+1);
    dfs(accept,board,x+1,y-1,word,pos+1);
    dfs(accept,board,x-1,y+1,word,pos+1);
    dfs(accept,board,x-1,y-1,word,pos+1);
    
    board[x][y]=temp;
    
}

vector<string> boggle(vector<vector<char> >& board,
                      vector<string>& dictionary) {
    // Your code goes here
    vector<string>v;
    for(int k=0;k<dictionary.size();k++)
    {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==dictionary[k][0])
                {
                    bool accept=false;
                    dfs(accept,board,i,j,dictionary[k],0);
                  if(accept==true)
                  {
                      v.push_back(dictionary[k]);
                      i=board.size();
                      j=board[0].size();
                  }
                }
            }
        }
    }
    return v;
}

/*\
1
4
GEEKS FOR QUIZ GO
3 3
G I Z 
U E K 
Q S E
Output:
GEEKS QUIZ
