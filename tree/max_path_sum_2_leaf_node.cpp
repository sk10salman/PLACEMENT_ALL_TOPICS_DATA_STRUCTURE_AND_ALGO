int solve(Node *root, int &max_sum)
{
   if(root==NULL)
     return 0;
    if(root->left==NULL&&root->right==NULL)
      return root->data;
    int l=solve(root->left,max_sum);
    int r=solve(root->right,max_sum);
    int temp=max(l,r)+root->data;
    //int ans=max(temp,l+r+root->data);
    if(root->left!=NULL&&root->right!=NULL)
   { max_sum = max(max_sum,l+r+root->data);
       return temp;
   }
  return (root->left==NULL)?root->data+r:root->data+l;
}
int maxPathSum(struct Node *root)
{
//add code here.
int maxsum = INT_MIN;

solve(root, maxsum);
return maxsum;
}
