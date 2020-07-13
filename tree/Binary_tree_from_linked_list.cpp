
/*
Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree.
Note : The complete binary tree is represented as a linked list in a way where if root node is stored at position i, its left, and right children are stored at position 2*i+1, 2*i+2 respectively.



The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

/*You are required to complete this method*/
TreeNode *insert(TreeNode *root,int data)
{
    if(root==NULL)
      {
          TreeNode *temp=new TreeNode(data);
          return temp;
      }
     if(root->data>=data)
     {
         root->left=insert(root->left,data);
     }
      if(root->data<data)
     {
         root->right=insert(root->right,data);
     }
}
TreeNode *solve(vector<int>v,int i,int n)
{
    if(i>n)
      return NULL;
    TreeNode *root=new TreeNode(v[i]);
    root->left=solve(v,2*i+1,n);
    root->right=solve(v,2*i+2,n);
    return root;
}
void convert(Node *head, TreeNode *&root) {
    // Your code here
    vector<int>v;
    Node *p=head;
    while(p)
    {
        v.push_back(p->data);
        p=p->next;
    }
    root = solve(v,0,v.size()-1);
}

