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


Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
 */
class Solution {
public:
      vector<vector<int>>v1;
    void print(vector<int>v5)   // print all path root to leaf for practice;
    {
        for(auto x:v5)
            cout<<x<<" ";
          cout<<"    ";
    }
        
    void solve(TreeNode* root, int sum,vector<int>v)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL&&root->right==NULL)
        {
            v.push_back(root->val);
            print(v);
            if(accumulate(v.begin(),v.end(),0)==sum)
                v1.push_back(v);
            return;
        }
   
        v.push_back(root->val);
        solve(root->left,sum,v);
         solve(root->right,sum,v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      
        if(root==NULL)
             return v1;
        vector<int>v;
        solve(root,sum,v);
        return v1;
    }
};
