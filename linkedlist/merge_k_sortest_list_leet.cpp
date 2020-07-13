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
    ListNode* insert(ListNode *head,int data)
    {
        ListNode *temp = new ListNode(data);
        if(head==NULL)
             return temp;
        else
        {
            temp->next=head;
            head=temp;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>v;
        for(int i=0;i<lists.size();i++)
        {
            while(lists[i]!=NULL)
            { v.push_back(lists[i]->val);
             lists[i] = lists[i]->next;
            }
        }
        sort(v.begin(),v.end());
        ListNode * start=NULL;
        for(int i=v.size()-1;i>=0;i--)
            
            start = insert(start,v[i]);
        return start;
        
    }
};





/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

*/
