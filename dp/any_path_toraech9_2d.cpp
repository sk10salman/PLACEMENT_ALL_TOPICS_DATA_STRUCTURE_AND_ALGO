#include<bits/stdc++.h>
using namespace std;
bool valid(int i,int j)
{
    if(i<0 || j<0 || i>=4 || j>=5)
        return false;
    return true;
}
bool solve(int mat[4][5],int n,int m,int i,int j)
{
     if(!valid(i,j) || mat[i][j]==0)
        return false;
    
    return (mat[i][j]==9)||solve(mat,n,m,i+1,j)||solve(mat,n,m,i,j+1);
       
}
int main()
{
   int mat[4][5]={{1,0,9,0,0},{1,0,0,0,0},{1,1,1,0,0},{1,0,0,0,1}};
   
   if(solve(mat,4,5,0,0))
      cout<<"yes"<<endl;
    else
      cout<<"No"<<endl;
  return 0;
}