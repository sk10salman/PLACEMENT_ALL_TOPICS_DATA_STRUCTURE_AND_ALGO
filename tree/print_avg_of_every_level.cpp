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
    vector<double> averageOfLevels(TreeNode* root) {
        
        
        vector<double>v;
        if(root==NULL)
              return v;
        queue<TreeNode*>q;
        q.push(root);
      int c=0;
        while(!q.empty())
        {
            int count=q.size();
           long long sum=0;
            for(int i=0;i<count;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
              sum += temp->val;
                if(temp->left)
                     q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
          
            double x=sum*1.0/count;
            v.push_back(x);
            
        }
       
        return v;
        
    }
};

/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
