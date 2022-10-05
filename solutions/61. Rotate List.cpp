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
    int getCountNodes(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        int size = getCountNodes(head);
        k = k % size;
        if(k == 0) return head;
        k = size - k;
        ListNode* newHead = NULL;
        ListNode* curr = head;
        for(int i =1;i<k;i++){
            curr = curr->next;
        }
        newHead = curr->next;
        curr->next = NULL;
        curr = newHead;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = head;
        return newHead;
    }
