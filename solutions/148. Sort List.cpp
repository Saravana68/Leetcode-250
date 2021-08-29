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
​
  /* BRUTEFORCE APPROACH:
     01.Using vector<int> and copying all elements of list into vector 
     02. sorting vector using sort() function
     03. again traversing list and vector and inserting values of vector into each nodes
     04.return head;
     TIME COMPLEXITY: O(NLOGN)
     SPACE COMPLEXITY: O(N)
  */
 
  /* OPTIMAL APPROACH
      01.using merge sort for sorting
      02. divide list into two equal halves using getMid function
      03. sort head to mid as left part
      04. sort mid to end as right part
      05. merge left and right part
      06. return new head;
      TIME COMPLEXITY : O(NLOGN) 
      SPACE COMPLEXITY : O(1)
  */
  
  //FIRST TIME SOLVED : 30.08.2021
​
class Solution {
public:
    
    ListNode * getMid(ListNode * head)
    {
        ListNode* midPrev = NULL;
        while (head && head->next) {
            midPrev = (midPrev == NULL) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = NULL;
        return mid;
    }
    
    ListNode * merge ( ListNode * list1, ListNode* list2)
    {
        ListNode * dummy  = new ListNode(0);
        ListNode * mergehead = dummy;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
