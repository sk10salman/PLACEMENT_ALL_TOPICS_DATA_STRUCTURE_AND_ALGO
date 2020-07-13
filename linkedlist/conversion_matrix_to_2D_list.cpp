/*structure of the node of the linked list is as
struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};
*/
// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]
struct Node* solve(int mat[MAX][MAX],int i,int j,int n){
    if(i>=n || j>=n)
      return NULL;
    struct Node* temp=new Node(mat[i][j]);
    temp->right=solve(mat,i,j+1,n);
    temp->down=solve(mat,i+1,j,n);
    return temp;
}

Node* constructLinkedMatrix(int mat[MAX][MAX], int n){
   return solve(mat,0,0,n);
}
/*
Input : 2D matrix 
1 2 3
4 5 6
7 8 9

Output :
1 -> 2 -> 3 -> NULL
|    |    |
v    v    v
4 -> 5 -> 6 -> NULL
|    |    |
v    v    v
7 -> 8 -> 9 -> NULL
|    |    |
v    v    v
NULL NULL NULL
*/
