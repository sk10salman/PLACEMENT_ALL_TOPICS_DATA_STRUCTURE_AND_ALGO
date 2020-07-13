/*
Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(int mat[][20],int x,int y,int n,bool &flag)
{
    if(x<0||x>=n||y<0||y>=n||mat[x][y]==0)
      return;
     if(mat[x][y]==2)
       flag = true;
      mat[x][y]=0;
     solve(mat,x-1,y,n,flag);
     solve(mat,x+1,y,n,flag);
     solve(mat,x,y-1,n,flag);
     solve(mat,x,y+1,n,flag);
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x,y;
	    cin>>n;
	    x=n,y=n;
	    int mat[20][20];
	    for(int i=0;i<n;i++)
	     for(int j=0;j<n;j++)
	     {
	         cin>>mat[i][j];
	         if(mat[i][j]==1)
	         {
	             x=i,y=j;
	         }
	     }
	     bool flag=false;
	     solve(mat,x,y,n,flag);
	     if(flag)
	       cout<<"1"<<endl;
	    else
	      cout<<"0"<<endl;
	}
	return 0;
}
