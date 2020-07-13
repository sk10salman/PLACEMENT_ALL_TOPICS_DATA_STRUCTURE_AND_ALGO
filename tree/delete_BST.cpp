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
    TreeNode *findMin_right(TreeNode* root)
    {
        TreeNode *cur=root;
        while(cur&&cur->left)
             cur=cur->left;
       return cur;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
              return NULL;
        if(root->val>key)
             root->left=deleteNode(root->left,key);
        else if(root->val<key)
             root->right=deleteNode(root->right,key);
        else
        {
            if(!root->left && !root->right)
            {
                root=NULL;
                delete root;
            }
           else if(root->left==NULL)
            {
                TreeNode *temp=root;
                root=root->right;
                delete temp;
            }
            else if(root->right==NULL)
            {
                TreeNode *temp=root;
                root=root->left;
                delete temp;
            }
            else
            {
              TreeNode *temp=findMin_right(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right,temp->val);
            }
        }
        return root;
    }
};

/*

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
*/
