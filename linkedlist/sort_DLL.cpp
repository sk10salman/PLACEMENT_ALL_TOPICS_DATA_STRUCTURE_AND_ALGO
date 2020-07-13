#include<bits/stdc++.h>
void insert(struct Node **head, int data);
struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	if(head==NULL)
	 return NULL;
	 vector<int>v;
	 Node *p=head;
	 while(p)
	 {
	     v.push_back(p->data);
	     p=p->next;
	 }
	 Node *head1=NULL;
	 sort(v.begin(),v.end());
	 for(int x=v.size()-1;x>=0;x--)
	   insert(&head1,v[x]);
	  return head1;
}
