void solve(Node *head, vector<Node*>&v)
{
    if(!head)
      return;
     solve(head->left,v);
     v.push_back(head);
     if(v.size()>=2)
      { int x=v.size();
      v[x-2]->right=v[x-1];
      v[x-1]->left=v[x-2];}
      solve(head->right,v);
      
}
Node *bTreeToCList(Node *root)
{
//add code here.
   vector<Node*>v;
   
   solve(root,v);
   v[0]->left=v.back();
   v.back()->right=v[0];
   return v[0];
}


/*
Given a Binary Tree of N edges. The task is to convert this to a Circular Doubly Linked List(CDLL) in-place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted CDLL. The order of nodes in CDLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the CDLL.
