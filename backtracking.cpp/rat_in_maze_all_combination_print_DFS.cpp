// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
bool vis[MAX][MAX];
bool is_safe(int m[][MAX],bool vis[][MAX],int r,int c,int n){
    if(vis[r][c] || r>=n || r<0 || c>=n || c<0 || m[r][c]==0)
        return 0;
    return 1;
}
void backtrack(vector<string>&result,int x,int y,string row,int n,int m[MAX][MAX])
{
     if(x==n-1 && y==n-1)
     {
         result.push_back(row);
         return;
     }
     int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
char dir[] = {'R','L','U','D'};
  vis[x][y]=1;
  for(int k=0;k<4;k++)
  {
      int x1=x+dx[k];
      int y1=y+dy[k];
      if(is_safe(m,vis,x1,y1,n))
      {
         
          backtrack(result,x1,y1,row+dir[k],n,m);
      }
  }
  vis[x][y]=0;
    
}
vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    memset(vis,0,sizeof(vis));
    vector<string>result;
    string row="";
if(is_safe(m,vis,0,0,n))
     backtrack(result,0,0,row,n,m);
     
     sort(result.begin(),result.end());
     if(result.size()==0)
       result.push_back("-1");
      return result;
}

/*
3
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
2
1 0 1 0 

Output:
DRDDRR
DDRDRR DRDDRR
-1

Explanation:
Testcase 2: The given input is in the form
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR when printed in sorted order we get DDRDRR DRDDRR.

