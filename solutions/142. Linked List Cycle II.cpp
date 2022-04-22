/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getHead(ListNode* slow,ListNode* head){
        while(head!= slow){
            slow = slow->next;
            head = head->next;
        }
        return slow;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
               return getHead(slow,head);
        }
        return NULL;
    }
};
