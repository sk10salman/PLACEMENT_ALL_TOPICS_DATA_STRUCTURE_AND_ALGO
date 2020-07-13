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
    int m=0;
    int solve1(TreeNode *root,int data)
    {
        if(root==NULL||root->val!=data)
            return 0;
        return 1+max(solve1(root->left,data),solve1(root->right,data));
    }
    void solve(TreeNode *root)
    {
        if(root==NULL)
            return;
        m=max(solve1(root->left,root->val)+solve1(root->right,root->val),m);
        solve(root->left);
        solve(root->right);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)
            return 0;
        solve(root);
        return m;
    }
};



/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

 
