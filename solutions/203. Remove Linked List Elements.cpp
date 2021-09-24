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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        
        if(head->next == NULL && head->val == val)
             return NULL;
        
        ListNode * start ,*end;
        start = end = NULL;
        ListNode * curr = head;
        while(curr)
        {
           if(curr->val != val)
           {
               if(!start){
                   start = end = curr;
               }
              else
              {
                end->next = curr;
                end = end->next;
              }
           }
            curr = curr->next;
        }
        end == NULL ? end = NULL : end->next = NULL;
        return start;
    }
};
