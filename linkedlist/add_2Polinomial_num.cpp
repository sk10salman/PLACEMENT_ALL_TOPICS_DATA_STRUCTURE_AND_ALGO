/*
2
1
1 2
1
1 3
2
1 3 2 2
2
3 3 4 2
Output:
1x^3 + 1x^2
4x^3 + 6x^2

Explanation:
Testcase 1: Since, x2 and x3 both have different powers as 2 and 3. So, their coefficient can't be added up.

Testcase 2: Since, x3 has two different coefficients as 3 and 1. Adding them up will lead to 4x3. Also, x2 has two coefficients as 4 and 2. So, adding them up will give 6x2.
*/





#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
/*
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node* new_node = new Node(new_data, new_data1);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
       printf("%d %d ", temp->coeff, temp->pow);
       temp  = temp->next;
    }
}

Node* addPolynomial(Node *p1, Node *p2);


void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}
 

/* Driver program to test above function*/
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }
        
         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }
        
        Node *sum = addPolynomial(poly1,poly2);
        for(Node* ptr=sum ; ptr ; ptr=ptr->next  )
        {
            // printing polynomial
            cout<< ptr->coeff << "x^" << ptr->pow;
            if(ptr->next) cout<<" + ";
        }
        cout<<endl;
       
    }

}
// } Driver Code Ends


/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};
*/

/* The below method print the required sum of polynomial
p1 and p2 as specified in output  */
//https://practice.geeksforgeeks.org/problems/polynomial-addition/1/?track=amazon-linkedlists&batchId=192 addPolynomial(Node *p1, Node *p2)
Node* addPolynomial(Node *p1, Node *p2)
{
    //Your code here
    map<int,int>m;
    while(p1)
    {
        m[p1->pow] +=p1->coeff;
        p1=p1->next;
    }
     while(p2)
    {
        m[p2->pow] +=p2->coeff;
        p2=p2->next;
    }
    Node *start=NULL;
   // Node *temp=start;
    for(auto i=m.begin();i!=m.end();i++)
    {
        Node *temp1=new Node(i->second,i->first);
        temp1->next=start;
        start=temp1;
    }
    return start;
    
}

