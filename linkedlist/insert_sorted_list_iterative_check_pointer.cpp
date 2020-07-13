
// Should return head of the modified linked list
Node *sortedInsert(struct Node* head, int data) {

    Node *start=new Node(0);
    Node *temp=start,*p=head;
    bool flag=false;
    while(p)
    {
        if(p->data>=data)
        {
            Node *temp1=new Node(data);
            temp->next=temp1;
            temp=temp1;
            temp->next=p;
            flag=true;
            break;
        }
        else{
             Node *temp1=new Node(p->data);
            temp->next=temp1;
            temp=temp1;
            p=p->next;
        }
        
    }
    if(flag==false)
    {
        Node *temp1=new Node(data);
            temp->next=temp1;
            temp=temp1;
    }
    return start->next;
}


/*
2
6
25 36 47 58 69 80
19
2
50 100
75

Output:
19 25 36 47 58 69 80
50 75 100

Explanation:
Testcase 1: After inserting 19 at particular place, the linked list is like 19, 25, 36, 47, 58, 69, 80.
