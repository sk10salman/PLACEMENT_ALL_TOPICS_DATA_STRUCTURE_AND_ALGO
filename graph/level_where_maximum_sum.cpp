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
    priority_queue<pair<int,int>>pq;
    int maxLevelSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(root==NULL)
            return 0;
        int level=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int sum=0;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                sum += temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            pq.push({sum,level});
            level++;
        }
        return pq.top().second;
    }
};
/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.

 

Example 1:



Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
