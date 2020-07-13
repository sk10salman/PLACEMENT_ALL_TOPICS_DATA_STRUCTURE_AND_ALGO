/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>v;
    
    void solve(TreeNode *root)
    {
        if(root==NULL)
             return;
        
        v.push_back(root->val);
        solve(root->left);
        solve(root->right);
        
    }
    void flatten(TreeNode* root) {
        if(root==NULL)
             return ;
        solve(root);
        TreeNode *start= root;
         TreeNode *temp=start;
        for(int i=1;i<v.size();i++)
        {
             TreeNode *temp1=new TreeNode(v[i]);
              temp->right=temp1;
            temp->left=NULL;
            temp=temp1;
        }
       
    }
};

/*
For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
