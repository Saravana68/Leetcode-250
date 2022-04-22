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
    ListNode* reverseKGroup(ListNode* head, int k) {
         
        int size = 0;
         ListNode * dummy = head;
         while(dummy){
             dummy = dummy->next;
             size++;
         }
        
        ListNode * curr = head;
        ListNode * prevFirst = NULL;
        bool isFirstPass = true;
        while(curr){
            ListNode * first = curr,*prev = NULL;
            int count =0;
            while(curr && count<k && size>k  )
            {
                ListNode * next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            size = size-k;
            if(isFirstPass)
            {
                head = prev;
                isFirstPass = false;
            }
            else
            {
                prevFirst->next = prev;
            }
            prevFirst = first;
        }
        return head;
    }
};
