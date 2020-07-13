/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }
        if(slow!=fast)
            return NULL;
        if(slow==fast)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;//or return fast both are correct
        }
        return NULL;
    }
};

/*


