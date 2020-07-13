Node * removeDuplicates( Node *head) 
{
 // your code goes here
  set<int>s;
  s.insert(-1);
  Node *start=new Node(0);
  Node *temp=start;
  Node *p=head;
  while(p)
  {
      if(s.find(p->data)==s.end())
         {
             Node *temp1=new Node(p->data);
             temp->next=temp1;
             temp=temp1;
         }
         s.insert(p->data);
         p=p->next;
  }
  return start->next;
}

