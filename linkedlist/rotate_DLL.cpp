//User function Template for C++

/*
struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

struct node*update(struct node*start,int p)
{
    //Add your code here
    if(start==NULL)
      return start;
    node *head=new node(start->data);
    start=start->next;
    node *temp=head;
    p--;
    while(start && p>0)
    {
        node * temp1=new node(start->data);
        temp->next=temp1;
        temp1->prev=temp;
        temp=temp1;
        p--;
        start=start->next;
    }
    node *x=start;
    while(start->next)
    {
        start=start->next;
    }
    start->next=head;
    head->prev=start;
    return x;
}


/*
1
6 2
1 2 3 4 5 6

Output:
3 4 5 6 1 2

Explanation:
Testcase 1: Doubly linked list after rotating 2 nodes is: 3 4 5 6 1 2.
