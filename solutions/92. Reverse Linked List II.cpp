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
  
  /*  BRUTEFORCE APPROACH
     01.traverse upto left node 
     02.starting from left node insert values of each node into new vector
     03.do this until left reaches right
     04.again traverse from start upto left
     05.from left to right insert vector values in reverse order upto right
     06. return head;
     TIME COMPLEXITY : O(N)  
     SPACE COMPLEXITY: O(N)
    */
​
   /* OPTIMAL APPROACH
      01. traverse upto left node
      02. store left-1 node  as start
      03. left node as end
      04. start form left node upto right node reverse links not nodes
      05. after node will be at right+1 node
      06. make end node pointing that right+1 node
      07. if (left == 1) at that case return prev
      08. else return head;
      TIME COMPLEXITY : O(N) SPACE COMPLEXITY: O(1)
    */
      
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        
        ListNode * start = head;
        ListNode* curr = head;
        int counter=1;
        while(counter<left)
        {
            start = curr;
            curr= curr->next;
            counter++;
        }
        ListNode * end = curr;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(counter<=right)
        {
            next = curr-> next;
            curr->next= prev;
            prev = curr;
            curr = next;
            counter++;
        }
        start->next = prev;
        end->next = curr;
        
        if(left == 1) 
            return prev;
        else 
            return head;
        
    }
};
