Node* build(int in[],int pre[],int l,int r,int &i)
{
if(l>r||l<0||r<0)
return NULL;
Node *root=new Node(pre[i]);
int j;
for(j=l;j<=r;j++)
{
if(pre[i]==in[j])
break;
}
i++;
root->left=build(in,pre,l,j-1,i);
root->right=build(in,pre,j+1,r,i);
return root;
}

Node* buildTree(int in[],int pre[], int n,int inI =0)
{
//add code here.
    int i=0;
    return build(in,pre,0,n-1,i);
}

/*
 pre == root,left,right
 in == left,root,right



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

class Solution {
public:
    TreeNode *Build(vector<int>& preorder, vector<int>& inorder,int start,int end,int &i)
    {
        if(start>end)
             return NULL;
        TreeNode *root=new TreeNode(preorder[i]);
        i++;
        int j;
        for(j=start;j<=end;j++)
        {
            if(inorder[j]==root->val)
                 break;
        }
      root->left=Build(preorder,inorder,start,j-1,i);
        root->right=Build(preorder,inorder,j+1,end,i);
    return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()<=0)
             return NULL;
        int i=0;
        return Build(preorder,inorder,0,preorder.size()-1,i);
    }
};
*/
