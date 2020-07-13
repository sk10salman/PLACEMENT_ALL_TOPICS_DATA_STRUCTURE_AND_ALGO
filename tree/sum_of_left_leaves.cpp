void solve(int dp,Node *root,int &sum)
{
    if(root==NULL)
      return;
     if(dp==0 && root->left==NULL && root->right==NULL)
     {
         sum +=root->data;
         return;
     }
    solve(0,root->left,sum);
    solve(1,root->right,sum);
}
int leftLeavesSum(Node *root)
{
    // Code here
    if(root==NULL)
return 0;
/*
  method 2:
if(root->left!=NULL&&(root->left->left==NULL&&root->left->right==NULL))
return root->left->data+leftLeavesSum(root->right);
else
return leftLeavesSum(root->left)+leftLeavesSum(root->right);
  */
    int sum=0;
    solve(0,root->left,sum);
     solve(1,root->right,sum);
     return sum;
}

/*
Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \        /  \
 7    2      6    9
Output :
sum = 6 + 7 = 13
*/
