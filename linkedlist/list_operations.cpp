#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node * next;
};
node * beg(node *head,int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
     return temp;
     temp->next=head;
     head=temp;
     return head;
    
}
node * end(node *head,int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    node *p=head;
    if(head==NULL)
     return temp;

     while(p->next!=NULL)
       p=p->next;
       p->next=temp;
       temp->next=NULL;
       return head;
}   
 node * position(node *head,int data,int pos)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data=data;
    node *p =head;
    for(int i=1;i<pos-1&&p!=NULL;i++)
       p=p->next;
    temp->next=p->next;
    p->next=temp;
   return head;
    

}
node * reverse(node *head)
{
    node *start=NULL;
    while(head!=NULL)
      {
          node *temp;
          temp = (node *)malloc(sizeof(node));
          temp->data=head->data;
          temp->next=start;
          start=temp;
          head=head->next;
      }
      return start;
}
void middle(node *head)
{
    node *fast=head,*slow=head;
    while(fast!=NULL  && fast->next!=NULL&&  fast->next->next!=NULL )
     {
         slow = slow->next;
         fast = fast->next->next;
     }
     if(slow->next!=NULL)
      
     cout<<"\n middle element id :  "<<slow->data<<endl;
}
void print(node *head)
{
   cout<<"\n\nLIST  \n\n";
    while(head)
     {
         cout<<head->data<<" ";
         head = head->next;
     }
      cout<<endl;
     cout<<endl;
}
int main()
{
    node *head=NULL;
    while(1)
     {
         cout<<"1.beginning\t 2. end \t 3. position   \t 4. print \t 5 reverese \t 6 middle element \t .exit "<<endl;
         int choice ;
         cin>>choice;
         switch (choice)
         {
         case 1:
                 {int x;
                  cout<<"enter value :";
                 cin>>x;
                 head = beg(head,x);
                 break;}
         case 2:
               { int x;
                  cout<<"enter value :";
                 cin>>x;
                 head = end(head,x);
                 break;}
        case 3:
                {int x;
                  cout<<"enter value :";
                 cin>>x;
                 int p;
                   cout<<"enter pos :";
                 cin>>p;
                 head = position(head,x,p);
                break;}
        case 4:
              print(head);
              break;
         case 5:
             head = reverse(head);
             break;
            case 6:
              middle(head);
              break;
         default:
             exit(0);
         }
     }
     return 0;
}