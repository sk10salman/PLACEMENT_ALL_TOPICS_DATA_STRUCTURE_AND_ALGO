
/*You are required to complete below method */
int solve(Node *root)
{
    if(!root)
      return 0;
     if(!root->left&&!root->right)
      return 1;
     return solve(root->left)+solve(root->right);
}
void solve1(Node *root,vector<int>&v,int k)
{
    if(!root)
      return ;
    solve1(root->left,v,k);
     solve1(root->right,v,k);
    if((root->left||root->right)&&solve(root)==k)
       v.push_back(root->data);
       
}
void btWithKleaves(Node *ptr, int k)
{ 
    //your code here.
    vector<int>v;
    solve1(ptr,v,k);
    if(v.size()==0)
      cout<<"-1";
    else
       for(auto x:v)
       cout<<x<<" ";
    cout<<endl;
    
}

