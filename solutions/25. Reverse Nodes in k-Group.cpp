​
​
class Solution {
public:
    
    int getTotalNodes(ListNode* head){
        if(!head) return 0;
        int count = 0;
        while(head){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr= head;
        ListNode* prevHead = NULL;
        bool first = true;
        
        int numOfNodes = getTotalNodes(head);
        
        
        while(curr){
            ListNode* prev = NULL;
            ListNode* next = NULL;
            ListNode* currHead = curr;
            int count = 0;
            
            if(numOfNodes < k) break;
            
            while(curr && count < k){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
                numOfNodes--;
            }
            if(first) { head = prev; first = false; } 
            else { prevHead ->next = prev;}
            prevHead = currHead;
        }
        prevHead->next = curr;
        return head;
    }
};
