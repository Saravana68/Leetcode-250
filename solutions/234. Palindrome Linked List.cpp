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
    
   ListNode *reverse(ListNode *head){
        ListNode *curr=head, *prev=NULL, *next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return head=prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL ) return false;
        if(head->next == NULL) return true;
        if(head->next->next == NULL)
        {
            if(head->val == head->next->val)
             return true;
            else 
                return false;
        } 
        
        ListNode *curr=head, *slow=head, *fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(slow){
            if(slow->val!=curr->val) return 0;
            slow=slow->next;
            curr=curr->next;
        }
        return 1;
    }
};
    
    
    
