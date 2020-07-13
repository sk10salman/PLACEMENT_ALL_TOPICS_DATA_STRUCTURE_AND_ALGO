/* The function should print all the paths from root
 to leaf nodes of the binary tree */
void solve(Node *root,vector<int>&v)
{
    if(root==NULL)
      return ;
    v.push_back(root->data);
    if(root->left==NULL && root->right==NULL)
    {
        for(auto x:v)
          cout<<x<<" ";
         cout<<"#";
         
       
    }
     
        solve(root->left,v);
       
          solve(root->right,v);
           v.pop_back();
        
}
void printPaths(Node* root)
{
    // Code here
    if(root==NULL)
    return;
    vector<int>v;
   
   solve(root,v);
   cout<<"\n";
}
