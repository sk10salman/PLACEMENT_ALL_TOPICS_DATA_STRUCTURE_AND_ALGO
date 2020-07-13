// your task is to complete this function
void solve(Node *root,Node *&n1,Node *&n2)
{
    if(root==NULL)
      return;
   
     if(root->left==NULL&&root->right==NULL)
     {
         if(n1==NULL)
         {
             n1=root;
         }
         else if(n2==NULL)
         {
             n2=root;
         }
         if(n1!=NULL&&n2!=NULL)
         {
              int temp=n1->data;
       n1->data=n2->data;
n2->data=temp;
n1=NULL;
n2=NULL;
         }
     }
          solve(root->left,n1,n2);
     solve(root->right,n1,n2);
     
    
    
}
void pairwiseSwap(Node *root)
{
    // code here
    Node *n1=NULL,*n2=NULL;
    solve(root,n1,n2);
}
/*
Given a binary tree of size N, your task is to complete the function pairwiseSwap(), that swap leaf nodes in the given binary tree pairwise starting from from left to right.
