void solve(Node *node,int d,int &depth)
{
    if(node==NULL)
      return ;
     if(node->left==NULL && node->right==NULL)
     {
         depth=min(depth,d);
     }
     solve(node->left,d+1,depth);
      solve(node->right,d+1,depth);
     
}
int minDepth(Node *node) {
    // Your code here
    if(node==NULL)
      return 0;
     int depth=INT_MAX;
     int d=1;
     solve(node,d,depth);
     return depth;
}
