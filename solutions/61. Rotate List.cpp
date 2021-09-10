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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head || !head->next)
            return head;
       int size = 0;
       ListNode * curr = head;
       ListNode * dummy = new ListNode();
       ListNode * temp = dummy;
       temp->next = head;
       while(curr)
       {
           size++;
           curr = curr->next;
       }
      size = k % size;
      ListNode * fast = head;
      ListNode * slow = head;
      while(size>0)
      {
          size--;
          fast = fast->next;
      }
      while(fast->next)
      {
