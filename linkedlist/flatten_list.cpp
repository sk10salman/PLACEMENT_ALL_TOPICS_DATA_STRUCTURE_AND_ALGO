struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
void solve(Node *root,vector<int>&v)
{
    if(root==NULL)
      return;
      v.push_back(root->data);
      solve(root->next,v);
      solve(root->bottom,v);
}
    
Node *flatten(Node *root)
{
   // Your code here
   vector<int>v;
   solve(root,v);
Node*start=new Node(0);
     Node *temp=start;
     sort(v.begin(),v.end());
     for(int i=0;i<v.size();i++)
     {
         Node *temp1=new Node(v[i]);
         temp->bottom=temp1;
         temp=temp1;
      //  cout<<v[i]<<" ";
     }
     return start->bottom;
}


/*

Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

You have to flatten the linked list to a single linked list which should be sorted.

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
And after flattening the above list, the sorted linked list looks like:

 5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.

Note: The flattened list will be printed using the bottom pointer instead of next pointer.


*/


