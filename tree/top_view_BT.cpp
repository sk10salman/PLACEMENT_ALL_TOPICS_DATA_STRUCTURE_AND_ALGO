#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    //Your code here
    if(root==NULL)
      return;
    map<int,vector<int>>m;
    queue<pair<Node*,int>>q;
    int hd=0;
    q.push({root,hd});
    while(!q.empty())
    {
        pair<Node*,int>temp=q.front();
        q.pop();
        hd = temp.second;
        Node *node = temp.first;
        m[hd].push_back(node->data);
        if(node->left)
          {
              q.push({node->left,hd-1});
          }
         if(node->right)
         {
             q.push({node->right,hd+1});
         }
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        vector<int>vc=it->second;
        //reverse(vc.begin(),vc.end());  bottom veiw ke liye comment hata do yeh wali
       // for(int j=0;j<vc.size();j++)    vertical traversal ke liye yeh wali 
           cout<<vc[0]<<" ";
    }
}



