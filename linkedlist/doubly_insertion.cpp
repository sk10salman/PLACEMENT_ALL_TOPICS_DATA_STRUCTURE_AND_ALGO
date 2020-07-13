#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int data;
    node *prev,*next;
};
node * newNode(int data)
{
    node *t;
    t = (node *)malloc(sizeof(node));
    t->data=data;
    t->next=NULL;
    t->prev=NULL;
    return t;
}
node * insert_beg(node *head,int data)
{
     node *temp= newNode(data);
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
node * insert_pos(node *head,int data,int pos)
{
     /*node *temp= newNode(data);
     node *p=head;
     if(head==NULL)
        head=temp;
    else
    {
        for(int i=1;i<pos-1&&p->next!=NULL;i++)
          p=p->next;
          p->next=temp;
          temp->prev=p;
          temp->next=p->next;
          p->next->prev=temp;
      
      
    
      //  temp->prev=p->next;
      //  temp->next=p->next;
    }*/
    return head;
    
}
node * insert_end(node *head,int data)
{
     node *temp= newNode(data);
     node *p=head;
     if(head==NULL)
        head=temp;
    else
    {
        while(p->next!=NULL)
         p=p->next;
           
          p->next=temp;
         temp->prev=p;
       
        
    }
    return head;
    
}
void print(node *head)
{
    node *p=head;
    if(head==NULL)
      return;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
}

int main()
{
    node *head=NULL;

    while(1)
    {
        int ch;
        cout<<"\n1.insert beg \t 2. insert end \t 3.insert nth \t4. print \t defalut.  Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                {
                    int x;
                    cout<<"enter value :";
                    cin>>x;
                    head = insert_beg(head,x);
                    break;
                }
            case 2:
               {
                    int x;
                    cout<<"enter value :";
                    cin>>x;
                    head = insert_end(head,x);
                    break;
               }
               case 3:
               {
                    int x;
                    cout<<"enter value :";
                    cin>>x;
                    int n;
                    cout<<"enter pos :";
                    cin>>n;
                    head = insert_pos(head,x,n);
                    break;
               }
               case 4:
               {
                   print(head);
                   break;
               }
               default :
                 exit(0);
                 break;
        }

    }
}