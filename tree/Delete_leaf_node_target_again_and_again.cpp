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
    TreeNode* solve(TreeNode* root, int target,int &count)
    {
        if(root==NULL ) 
          return NULL;
        if(root->left==NULL&&root->right==NULL&&root->val==target)
        {
            count++;
            return NULL;
        }
       
        root->left=solve(root->left,target,count);
        root->right=solve(root->right,target,count);
        return root;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
      if(root==NULL ) 
          return NULL;
       int count=0;
       root=solve(root,target,count);
    while(count>=1)
    {
        count=0;
         root=solve(root,target,count);
    }
       return root;  
    }
};

/*
Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
*/
