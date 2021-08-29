/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode * front  = new ListNode(0);
        ListNode * back   = new ListNode(0);
        ListNode * frontHead = front;
        ListNode * backHead = back;
        ListNode * curr = head;
        
        while(curr)
        {
           if(curr->val < x)
           {
               front -> next = curr;
               front = front ->next;
           }
           else if( curr ->val >=x)
           {
             back->next = curr;
             back = back->next;
           }
           curr = curr->next;
        }
        back->next = NULL;
        backHead = backHead->next;
        front->next = backHead;
        frontHead = frontHead -> next;
            
       return frontHead;
    }
};
