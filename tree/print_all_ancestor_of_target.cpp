bool printAncestors(struct Node *root, int target)
{
     // Code here
    if(root==NULL)
      return false;
     if(root->data==target)
       return true;
     if(printAncestors(root->left,target) || printAncestors(root->right,target))
         { cout<<root->data<<" ";
    return true;}
}
