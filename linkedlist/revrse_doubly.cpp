Node * insert_beg(Node *head,int data)
{
     Node *temp= new Node(data);
     if(head==NULL)
        head=temp;
    else
    {
         temp->next=head;
         head->prev=temp;
         head=temp;
    }
    return head;
    
}
Node* reverseDLL(Node * head)
{
    //Your code here
    Node *start=NULL;
   
    
    while(head)
    {
      start = insert_beg(start,head->data);
        head = head->next;
    }
    return start;
}
