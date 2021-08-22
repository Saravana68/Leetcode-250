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
 /* Bruteforce: 
    01.creating a new node 
    02.assigning all nodes of l1 and l2 to it
    03. sorting the new node using merge sort
    Time: O(nlogn) space: O(l1+l2)
 */
  /* optimal:
    01. create two struct pointer head and tail
    02. make both point to the start of merged sorted list
    03. use any of one pointer to traverse the both nodes  (head)
    04. return other pointer which points head of merged sorted linkedlist (tail)
    05. merging process : if l1->data > l2-> data append l2-> data and move l2 to next node
    06. else append l1->data and move next node of l1
    time: O(N) space: O(1)
    */
​
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
      if(l1==NULL)  return l2;
      if(l2==NULL) return l1;
      ListNode* head ,*tail;
        
        head = tail = NULL;
        if( l1->val <= l2->val)
        {
