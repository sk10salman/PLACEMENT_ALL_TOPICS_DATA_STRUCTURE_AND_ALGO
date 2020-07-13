#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

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
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
void mark_island(vector<vector<int>>&A,int x,int y,int r,int c,int &count)
{
    if(x<0||x>=r||y<0||y>=c||A[x][y]!=1)
      return;
     A[x][y]=2;
     count++;
     mark_island(A,x+1,y,r,c,count);
      mark_island(A,x-1,y,r,c,count);
       mark_island(A,x,y+1,r,c,count);
        mark_island(A,x,y-1,r,c,count);
         mark_island(A,x-1,y-1,r,c,count);
          mark_island(A,x+1,y-1,r,c,count);
           mark_island(A,x-1,y+1,r,c,count);
            mark_island(A,x+1,y+1,r,c,count);
     
}

int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    vector<vector<int>>mat;
    for(int i=0;i<N;i++)
      mat.push_back(A[i]);
    int no_of_island=0;
    for(int i=0;i<N;i++)
     for(int j=0;j<M;j++)
       {
           if(mat[i][j]==1)
             {
                 int count=0;
                 mark_island(mat,i,j,N,M,count);
                no_of_island=max(no_of_island,count);
             }
       }
      return no_of_island;
}

