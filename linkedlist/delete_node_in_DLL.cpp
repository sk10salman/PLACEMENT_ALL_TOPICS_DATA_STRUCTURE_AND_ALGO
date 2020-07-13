
// Function to delete the node at position x
void deleteNode(Node **head_ref, int x)
{
  //Your code here
  Node *prev,*p=*head_ref;
  if(x==1)
    { *head_ref=p->next;
        return;
    }
  prev=p;
  for(int i=1;i<x;i++)
  {
      prev=p;
      p=p->next;
  }
  prev->next=p->next;
}
