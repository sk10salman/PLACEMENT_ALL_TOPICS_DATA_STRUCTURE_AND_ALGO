/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
          vector<vector<int>>v;
        if(root==NULL)
              return v;
        queue<Node*>q;
        q.push(root);
      int c=0;
        while(!q.empty())
        {
            int count=q.size();
            vector<int>vec;
            for(int i=0;i<count;i++)
            {
                Node *cur=q.front();
                q.pop();
                vec.push_back(cur->val);
                for(auto it:cur->children)
                {
                    q.push(it);
                }
            }
            v.push_back(vec);
          
        }
     
        return v;
    }
};
