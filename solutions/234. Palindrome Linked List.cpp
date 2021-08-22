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
