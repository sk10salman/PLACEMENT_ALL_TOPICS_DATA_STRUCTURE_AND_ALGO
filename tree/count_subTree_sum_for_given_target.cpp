//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// your are required to complete this function
// function should return the count of the number of 
// subtrees with Sum equal to X
int sum(Node *root)
{
    if(root==NULL)
      return 0;
     return root->data+sum(root->left)+sum(root->right);
}
void solve(Node *root,int X,int &ans)
{
    if(root==NULL)
     return;
     int x1 = sum(root);
    // cout<<x1<<" ";
     if(x1==X)
      {
          ans +=1;
      }
     solve(root->left,X,ans);
     solve(root->right,X,ans);
}
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	if(root==NULL)
	  return 0;
	int ans=0;
	solve(root,X,ans);
	return ans;
}

