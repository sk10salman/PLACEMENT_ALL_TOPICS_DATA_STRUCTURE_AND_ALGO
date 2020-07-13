class Solution {
public:
    vector<int>v;
    void right(TreeNode* root,int level,int *max)
    {
        if(root==NULL)
            return;
        if(*max<level)
        {
            v.push_back(root->val);
            *max=level;
        }
        right(root->right,level+1,max);
        right(root->left,level+1,max);
    }
    vector<int> rightSideView(TreeNode* root) {
        int max=0;
        right(root,1,&max);
        return v;
    }
};
