/* Should return minimum distance between a and b
   in a tree with given root*/
 bool solve1(Node *root,int a,int &ax,int count)
 {
     if(root==NULL)
       return false;
      if(root->data==a)
       { ax=min(ax,count);
          return true;
       }
       
     return max(solve1(root->left,a,ax,count+1),solve1(root->right,a,ax,count+1));
 }
 void solve(Node *root,int a,int b,int &x)
 {
     if(root==NULL)
        return;
    int ax=INT_MAX;
    int bx=INT_MAX;
    int count1=0,count2=0;
     solve1(root,a,ax,count1);
     solve1(root,b,bx,count2);
     if(ax!=INT_MAX&&bx!=INT_MAX)
     x=min(x,abs(ax+bx));
    solve(root->left,a,b,x);
    solve(root->right,a,b,x);
    
 }
int findDist(Node* root, int a, int b) {
    // Your code here
    if(root==NULL)
     return 0;
   int x=INT_MAX;
   solve(root,a,b,x);
   return x;
}
