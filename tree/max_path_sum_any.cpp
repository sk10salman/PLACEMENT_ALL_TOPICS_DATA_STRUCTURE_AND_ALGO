
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int solve(Node *root,int &sum)
{
    if(root==NULL)
      return 0;
     int l=root->left?solve(root->left,sum):0;
     int r=root->right?solve(root->right,sum):0;
     int temp=max(root->data+max(l,r),root->data);
     int ans=max(temp,(l+r+root->data));
     sum = max(ans,sum);
     return temp;
}
int findMaxSum(Node* root)
{
    // Your code goes here
    if(root==NULL)
     return 0;
     int sum=INT_MIN;
     solve(root,sum);
     return sum;
}


