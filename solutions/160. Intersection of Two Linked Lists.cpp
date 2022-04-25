/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA){
            return headB;
        }
        if(!headB){
            return headA;
        }
        
        int sizeA=0 ,sizeB=0;
        ListNode * curr1 = headA;
        ListNode* curr2 = headB;
        while(curr1)
        {
            sizeA++;
            curr1= curr1->next;
        }
        while(curr2)
        {
            sizeB++;
            curr2 = curr2->next;
        }
        curr1 = headA;
        curr2 = headB;
        if(sizeA>sizeB)
        {
