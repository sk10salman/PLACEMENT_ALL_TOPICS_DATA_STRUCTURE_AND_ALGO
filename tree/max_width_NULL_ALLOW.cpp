class Solution {
public:

    int widthOfBinaryTree(TreeNode* root) {
       if(!root) return 0;
        long ans = 0;
        queue<pair<TreeNode*,int>> Q;
        Q.push({root,1});
        while(!Q.empty()) {
            long start = Q.front().second,end=start;
            int size = Q.size();
            for(int i=0; i<size; i++) {
                end = Q.front().second;
                TreeNode* node = Q.front().first;
                Q.pop();
                if(node->left) Q.push({node->left,2*end});
                if(node->right) Q.push({node->right,2*end+1});
            }
            ans = max(ans,end-start+1);
        }
        return ans;
    }
};

/*
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).

