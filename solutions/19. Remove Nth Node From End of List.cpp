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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
​
            
       if( head == NULL || head->next == NULL ) return NULL;
        
        ListNode * first  = head;
        ListNode* second =  head;
        int length = 0;
        while(second)
        {
            length++;
            second = second->next;
        }
        int range = length - n;
        if(range == 0)
            return head->next;
        
        for(int i = 1 ;i < range ; i++)
            first = first->next;
        
        
        first->next = first->next->next;
        return head;
        
        
         
    }
};
