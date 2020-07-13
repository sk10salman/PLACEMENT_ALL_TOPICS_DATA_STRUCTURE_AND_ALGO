/ This function should return head of
// the modified list
Node *sortedInsert(Node* head, int x)
{
   //Your code here
   Node *temp=new Node (x);
   if(!head)
     return temp;
    Node *p=head;
    Node *q=p,*z=head;
    while(z->next!=head)
      z=z->next;          ///// last Node
    if(x<=p->data)         //if first insert Node is minimum
       {temp->next=head;
          z->next=temp;
          return temp;
       }
      bool ac=false;
    while(p->next!=head)
    {
        q=p;
        p=p->next;
        if(q->data<=x&&x<=p->data)
        {
           q->next=temp;
           temp->next=p;
           ac=true;
           return head;
        }
    }
    if(ac==false)
    {
        p->next=temp;
        temp->next=head;
    }
    return head;
}
