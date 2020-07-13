void solve1(int data,Node* root,int &mx)
{
    if(root==NULL)
       return;
    mx= max(data-root->data,mx);
    solve1(data,root->left,mx);
    solve1(data,root->right,mx);
}
void solve(Node* root,int &mx)
{
    if(root==NULL)
      return ;
    solve1(root->data,root->left,mx);
    solve1(root->data,root->right,mx);
    
     solve(root->left,mx);
    solve(root->right,mx);
     
}
int maxDiff(Node* root)
{
    // Your code here 
    if(root==NULL)
     return 0;
     int mx=INT_MIN;
     solve(root,mx);
     return mx;
}

