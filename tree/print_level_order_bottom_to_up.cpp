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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>v;
        if(root==NULL)
              return v;
        queue<TreeNode*>q;
        q.push(root);
      int c=0;
        while(!q.empty())
        {
            int count=q.size();
            vector<int>vc;
            for(int i=0;i<count;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                vc.push_back(temp->val);
                if(temp->left)
                     q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            v.push_back(vc);
          
        }
       reverse(v.begin(),v.end());
        return v;
        
    }
};


/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

