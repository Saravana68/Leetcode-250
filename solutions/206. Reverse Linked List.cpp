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
/* bruteforce approach: 
   01.create a vector<int> v;
   02.traverse the linkedlist upto last Node 
   03. while traversing push_back Node-> data into vector
   04. now again traverse the linkedlist from front but traverse vector from last
   05. now insert data from vector in reverse order
   06. list reversed
   Time: O(N) space: O(N)
 */
​
  /* optimal approach
     01. instead of reversing data of node change links of node
     02. intialize ListNode* prev = NULL and make point first node to NULL
     03. update prev = current_node so that next node also points to prev which previous node of itself
     04.in last iteration prev becomes address of last node which is first node after reversing 
     05. so return prev
     Tim: O(N) space:O(1)
  */
​
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!= NULL)
        {
            ListNode*next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
        }
        return prev;
    }
};
