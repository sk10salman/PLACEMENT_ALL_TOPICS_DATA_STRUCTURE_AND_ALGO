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
  int sum;
    void fn(TreeNode* root, int dir){
        if(root==NULL){
            return;
        }
        if(dir == 0 && root->left==NULL && root->right==NULL){
            sum+=root->val;
            return;
        }
        fn(root->left,0);
        fn(root->right,1);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        if(root==NULL){
            return 0 ;
        }
        fn(root->left,0);
        fn(root->right,1);
        return sum;
    }
};
