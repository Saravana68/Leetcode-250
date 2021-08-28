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
   
  ListNode * getReversed(ListNode * head)
  {
      ListNode * prev = NULL;
      while(head)
      {
          ListNode * next = head ->next;
          head ->next = prev;
          prev = head;
          head = next;
      }
      return prev;
  }
​
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* sum = new ListNode(0);
        ListNode * sumHead = sum;
        l1 = getReversed(l1);
        l2 = getReversed(l2);
        int carry =0;
        while(l1 || l2)
        {
