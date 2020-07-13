#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M,int x,int y);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
         
        }
         int x,y;
          cin>>x>>y;
        cout << findIslands(A, N, M,x,y) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
set<int>s;
void mark_island(vector<vector<int>>A,int x,int y,vector<vector<int>>vis,int r,int c,int count,int t1,int t2)
{
    if(x<0||x>=r||y<0||y>=c||A[x][y]!=1||vis[x][y]==true)
      return;
      if(x==t1&& y==t2)
       s.insert(count);
     vis[x][y]=true;
     count++;
     
     mark_island(A,x+1,y,vis,r,c,count,t1,t2);
      mark_island(A,x-1,y,vis,r,c,count,t1,t2);
       mark_island(A,x,y+1,vis,r,c,count,t1,t2);
        mark_island(A,x,y-1,vis,r,c,count,t1,t2);
         
     
}

int findIslands(vector<int> A[], int N, int M,int x,int y) {

    // Your code here
    vector<vector<int>>mat;
    for(int i=0;i<N;i++)
      mat.push_back(A[i]);
    int no_of_island=0;
   vector<vector<int>>vis(N,vector<int>(M,false));
                 int count=0;
                 mark_island(mat,0,0,vis,N,M,count,x,y);
                
       
       int m=-1;
      if(!s.empty())
        m=*s.begin();
    s.clear();
      return m;
}

