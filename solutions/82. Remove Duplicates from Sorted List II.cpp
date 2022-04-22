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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* NewHead = new ListNode(-101);
        ListNode* Tail = NewHead;
        ListNode* curr = head;
        
        int count =0;
        while(curr){
            
            count =0;
            while( curr->next && curr->val == curr->next->val){
                count++;
                curr->next = curr->next->next;
            }
            if(count == 0){
                Tail->next = curr;
                Tail = Tail->next;
            }
            curr = curr->next;
        }
        Tail->next = NULL;
        return NewHead->next;
    }
};
