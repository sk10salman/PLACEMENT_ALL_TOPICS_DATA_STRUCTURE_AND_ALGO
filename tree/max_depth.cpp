int maxDepth(TreeNode* root) {
        if(root==NULL)
              return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }

/*

 3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

*/
