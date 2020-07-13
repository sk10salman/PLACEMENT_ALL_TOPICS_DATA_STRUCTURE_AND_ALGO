
/* structure for a node 
struct Node
{
	int data;
	struct Node *next;
};
*/

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{

// Your code goes here
  Node *p=*head,*q=*head;
  while(p->next!=q)
  {
      Node *pre=p;
      p=p->next;
      if(p!=NULL && p->data==key)
      {
          pre->next=p->next;
          break;
      }
  }

}

/* Function to reverse the linked list */
 void reverse(struct Node** head)
{

Node *cur=*head,*prev=NULL,*next;
do{
next=cur->next;
cur->next=prev;
prev=cur;
cur=next;
}while(cur!=*head);
cur->next=prev;
*head=prev;

}


/*
Input:
2
5
2 5 7 8 10
8
4
1 7 8 10
8

Output:
10 7 5 2 
10 7 1

Explanation:
Testcase 1: After deleting 8 from the given circular linked list, it has elements as 2, 5, 7, 10. Now, reversing this list will result in 10, 7, 5, 2.
