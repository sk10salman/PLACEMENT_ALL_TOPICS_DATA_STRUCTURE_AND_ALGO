// Should return the head of the copied linked list the
// output will be 1 if successfully copied
Node *copyList(Node *head) {
    // Your code here
    map<Node*,Node*>m;
    Node *p=head;
    Node *temp1=new Node(head->data);
    m[head]=temp1;
  
    while(p)
    {
        Node *pre=p;
          p=p->next;
       if(p){ Node *temp=new Node(p->data);
          m[p]=temp;
        m[pre]->next=temp;}
    }
    Node *a=head;
    while(a)
    {
       Node *temp2=a->arb;
       m[a]->arb=temp2;
       a=a->next;
    }
    return m[head];
}
/*
You are given a Singly Linked List with N nodes where each node next pointing to its next node. You are also given M random pointers , where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.
