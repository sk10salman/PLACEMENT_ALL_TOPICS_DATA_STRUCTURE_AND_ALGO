 Tree* solve(Tree* root) {
      // Write your code here
      if(root==NULL)
        return NULL;
       root->left=solve(root->left);
       root->right=solve(root->right);
       if(root->left==NULL&&root->right==NULL&&root->val==0 )
        return NULL;
    return root;
         
      
  }
};
/*
Given a binary tree where all nodes are either 0 or 1, prune the tree so that
subtrees containing all 0s are removed.

For example, given the following tree:

   0
  / \
 1   0
    / \
   1   0
  / \
 0   0
should be pruned to:

   0
  / \
 1   0
    /
   1


