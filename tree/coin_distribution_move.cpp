Given the root of a binary tree with N nodes, each node in the tree has node.val coins, and there are N coins total.

In one move, we may choose two adjacent nodes and move one coin from one node to another.  (The move may be from parent to child, or from child to parent.)

Return the number of moves required to make every node have exactly one coin.




class Solution {
public:
   int dfs(TreeNode* root,int &steps)
    {
        if(!root)return 0;
        int l=dfs(root->left,steps);
        steps+=abs(l);
        int r=dfs(root->right,steps);
        steps+=abs(r);
        root->val+=l+r;
        return root->val-1;
        
    }
    int distributeCoins(TreeNode* root) {
        if(!root)return 0;
        int steps=0;
        dfs(root,steps);
        return steps;
    }
};
