/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
         using Node =ListNode;
        if(head==NULL)
             return NULL;
        ListNode* odd=new Node(head->val),*even=NULL;
        head=head->next;
        if(head!=NULL)
        { even=new Node(head->val);
        head=head->next;}
        
        ListNode*p=odd,*q=even;
        
        while(head!=NULL )
        {
           Node*temp=new Node(head->val);
            p->next=temp;
            p=temp;
            head=head->next;
            if(head)
            {
             Node*temp=new Node(head->val);
            q->next=temp;
            q=temp;
            head=head->next;   
            }
        }
       p->next=even;
        return odd;
        
        
    }
};



/*

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL

*/
